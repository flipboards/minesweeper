#include"mine.h"

//Lattice Functions
lattice::lattice(){
	ismine = 0;
	state = STATE_CLOSED;
	label = 0;
}
void lattice::setmine(){
	ismine = 1;
}
void lattice::setneighbour(vector<lattice*> neighbour){
	this->neighbours = neighbour;
}
void lattice::setlabel(){
	for each(lattice* nb in neighbours){
		label += (int)nb->ismine;
	}
}
bool lattice::open(){
	if(ismine)this->state = STATE_KILLED;
	else this->state = STATE_OPENED;
	return ismine;
}
int lattice::getlabel()const{
	if(this->state == STATE_OPENED)return this->label;
	else return -1;
}

//Minemap functions
mineMap::mineMap(){
	m_lose = 0;
	m_lattices = 0;
	m_state = M_UNSTART;
}
mineMap::mineMap(int width,int height){
	m_width = width;
	m_height = height;
	m_lose = 0;
	m_lattices = 0;
	m_state = M_UNSTART;
}
mineMap::~mineMap(){
	if(m_state != M_UNSTART)
		delete[] m_lattices;
}

lattice* mineMap::getLattice(int x,int y)const{
	return m_lattices + x + y*m_width;
}
vector<lattice*> mineMap::setNeighbour(lattice* me){

	int index = me - m_lattices;
	vector<lattice*> neighbour;

	int right = Min(index %m_width +1,m_width-1);
	int bottom = Min(index /m_width +1,m_height-1);
	for(int i = Max(index %m_width -1, 0); i <= right; i++){
		for(int j= Max(index /m_width -1, 0);j <= bottom; j++){
			neighbour.push_back(getLattice(i,j));
		}
	}
	return neighbour;
}
int mineMap::Open(lattice* Lattice){

	if(Lattice->state != STATE_CLOSED)return 0;
	if(Lattice->open()){m_state=M_LOSE;return 0;}		//gameover!
	
	if(Lattice->getlabel() == 0){

		for each(lattice* neighbour in Lattice->neighbours){
			if(neighbour->state == STATE_CLOSED){this->Open(neighbour);}
		}
	}
	m_opennumber++;
	return 1;
}
int mineMap::FastOpen(lattice* Lattice){
	if(Lattice->state!=STATE_OPENED)return 0;

	int count=0;//实际雷数
	for each(lattice* neighbour in Lattice->neighbours){
		if(neighbour->state==STATE_MARKED)count++;	//计算周围没开过雷的个数
	}
	if(count != Lattice->getlabel())return 0;			//判断要开的雷数目是否等于标记的个数
	
	for each(lattice* neighbour in Lattice->neighbours){
		if(neighbour->state==STATE_CLOSED)this->Open(neighbour);
	}
	return 1;
}
int mineMap::Mark(lattice* Lattice){
	if(Lattice->state==STATE_CLOSED){Lattice->state=STATE_MARKED;m_mineleft--;}
	else if(Lattice->state==STATE_MARKED){Lattice->state=STATE_CLOSED;m_mineleft++;}
	
	return 1;
}

//mineMap public functions
void mineMap::Set(int width, int height, int mineNumber) {
	m_width = width;
	m_height = height;
	m_minenumber = mineNumber;
	m_mineleft = m_minenumber;
	m_lattices = 0;
	if (mineNumber > m_width * m_height - 1) {
		cout << "To much mines!" << endl;
		mineNumber = m_width * m_height - 1;
	}
	m_state = M_UNSTART;
}

int mineMap::Generate(int seedX,int seedY){
	m_mineleft = m_minenumber;
	m_opennumber = 0;
	m_lose=0;
	
	//generate map
	m_lattices=new lattice[m_width*m_height];
	for(int i=0;i<m_width*m_height;i++)
		m_lattices[i].setneighbour(setNeighbour(m_lattices + i));

	//generate mines	
generate:	
	int* mines = randomChoose(m_width*m_height, m_minenumber);
	
	for each(lattice* nb in getLattice(seedX,seedY)->neighbours){
		if(find(mines,mines + m_minenumber,nb - m_lattices)!=( mines + m_minenumber))goto generate;
	}

	for(int i=0;i<m_minenumber;i++)
		m_lattices[mines[i]].setmine();
	delete mines;

	//calculate the label of each lattice
	for(int i = 0; i <m_width*m_height ; i++)
		m_lattices[i].setlabel();

	m_state = M_NORMAL;
	return 1;
}
int mineMap::Open(int x,int y){
	//cout<<"x="<<x<<", y="<<y<<" state="<<getLattice(x,y)->state<<" label="<<getLattice(x,y)->label<<endl;
	return this->Open(getLattice(x,y));
}
int mineMap::Mark(int x,int y){
	return this->Mark(getLattice(x,y));
}
int mineMap::FastOpen(int x,int y){
	return this->FastOpen(getLattice(x,y));
	
}
int mineMap::GameState()const{
	
	if (m_minenumber == m_width*m_height - m_opennumber) {
		return M_WIN;
	}
	else
		return m_state;
}
void mineMap::Clear() {
	delete[] m_lattices;
	m_state = M_UNSTART;
	m_lose = 0;
	m_opennumber = 0;
	m_minenumber = -1;
}

//solveMap Functions
int solveMap::Bind(mineMap* map){
	if(map ==0)return 0;
	else {
		m_map = map;
		mapsize = map->m_width*map->m_height;
		mineleft = new int[mapsize];
		nbleft = new int[mapsize];
		nbopen = new int[mapsize];
		for(int i = 0; i < mapsize; i++){
			mineleft[i] = 8;
			nbleft[i] = 8;
			nbopen[i] = 0;
		}
	}
	return 1;
}
solveMap::~solveMap(){
	delete mineleft;
	delete nbleft;
	delete nbopen;
}

//扫描基本数据，决定是否需要打开
void solveMap::scan()	//复杂度O(n)*nb
{
	for(int n = 0;n < mapsize; n++){
		//筛选出之前未处理的，打开的格子
		if(nbleft[n] > 0){
			
			mineleft[n] = m_map->m_lattices[n].getlabel();
			nbleft[n] = 0;
			nbopen[n] = 0;

			if (m_map->m_lattices[n].state == STATE_MARKED)continue;

			for each(lattice* neighbour in m_map->m_lattices[n].neighbours){
				if(neighbour->state == STATE_CLOSED)nbleft[n]++;
				else if(neighbour->state == STATE_MARKED)mineleft[n]--;
				else nbopen[n]++;
			}
		}
	}
	return;
}
//把显而易见的格子打开
int solveMap::justOpen()	//复杂度O(n)
{
	int opennumber = 0;

	for (int n = 0; n < mapsize; n++) {

		if (nbleft[n] > 0 && m_map->m_lattices[n].state == STATE_OPENED){	//only opened lattices are valued for test
			
			if (mineleft[n] == nbleft[n]) {		//if just left mine[n] neighbours, mark all of them
				for each(lattice* neighbour in m_map->m_lattices[n].neighbours) {
					if (neighbour->state == STATE_CLOSED)m_map->Mark(neighbour);
				}
				opennumber++;
			}
			else if (mineleft[n] == 0) {		//open fully marked lattices
				m_map->FastOpen(m_map->m_lattices + n);
				opennumber++;
			}
		}
	}
	return opennumber;
}
//局部概率计算，如1-2-1这种	(DFS)
int solveMap::getnbdetail(int index,vector<lattice*>& closednb,vector<lattice*>& openednb){

	for each(lattice* neighbour in m_map->m_lattices[index].neighbours){
		if(neighbour->state == STATE_CLOSED) closednb.push_back(neighbour);
		for each(lattice* neighbour2 in neighbour->neighbours){
			if(nbleft[neighbour2 - m_map->m_lattices]>0 && find(openednb.begin(), openednb.end(), neighbour2) == openednb.end())
				openednb.push_back(neighbour2);
		}
	}
	return openednb.size();
}
int solveMap::microProb(){	//复杂度O(n)*2^nb

	int solvenumber = 0;
	for(int n = 0;n < mapsize; n++){

		if(nbleft[n] >0 && m_map->m_lattices[n].state == STATE_OPENED){

			vector<lattice*> openednb, closednb;			//开过的格子和没开的格子,都是lattice*
			if(!getnbdetail(n,closednb,openednb))continue;

			//生成相关性矩阵 get common neighbours
			matrix covList(openednb.size(),closednb.size());
			vector<symbol> symbols(openednb.size(),le);
			
			for(unsigned int i = 0; i < openednb.size(); i++){
				int containmark = 0;
				for(unsigned int j = 0; j < closednb.size(); j++){
					//find if closednb is in openednb[i]'s neighbour
					if(find(openednb[i]->neighbours.begin(),openednb[i]->neighbours.end(),closednb[j]) != openednb[i]->neighbours.end()){
						covList.data[i][j] = 1;
						containmark ++;
					}
					else{
						covList.data[i][j] = 0;
					}
				}
				if(containmark == nbleft[openednb[i] - m_map->m_lattices]) symbols[i] = symbol::equal;
			}

			//解不定方程组
			vector<int> result(closednb.size(),0);
			vector<int> restrict;
			for(unsigned int i = 0; i < openednb.size(); i++){
				restrict.push_back(mineleft[openednb[i] - m_map->m_lattices]);
			}

			int cnt_result = intProgram(covList,restrict,result,symbols);
			
			//激动人心的时刻……
			for(unsigned int i=0; i < result.size(); i++){
				if(result[i] == cnt_result){		//所有情况都为1，标记
					m_map->Mark(closednb[i]);
					solvenumber ++;
				}
				else if(result[i] == 0){			//所有情况都没有，打开
					m_map->Open(closednb[i]);
					solvenumber ++;
				}
			}
		}
//		cout<<n<<endl;
	}
	return solvenumber;
}
//片状概率计算，并生成概率矩阵
int solveMap::pieceDetect(lattice* me, vector<lattice*>& closedpc, vector<lattice*>& openedpc, matrix& matcov, vector<bool>& record)
{
	
	vector<int> covline(closedpc.size(),0);		//准备放到矩阵中的一行

	bool includemark = false;
	for each(lattice* nb in me->neighbours) {
		if (nb->state == STATE_CLOSED) {
			vector<lattice*>::iterator it_nb = find(closedpc.begin(), closedpc.end(), nb);

			if (it_nb == closedpc.end()) {		//找不到，放进去
				closedpc.push_back(nb);
				covline.push_back(1);
			}
			else {								//找到了，标记
				covline[it_nb - closedpc.begin()] = 1;
				includemark = true;
			}
		}
		else if (nb!= me && nb->getlabel() > 0) {
			if(find(openedpc.begin(),openedpc.end(),nb)==openedpc.end()){
				pieceDetect(nb, closedpc, openedpc, matcov, record);
			}
		}
	}

	//要是符合条件就放入矩阵
	if (includemark) {
		openedpc.push_back(me);
		matcov.addline(covline);
		record[me - m_map->m_lattices] = true;
	}
	return openedpc.size();
}
int solveMap::pieceProb()
{
	vector<bool> record(mapsize, false);
	for (int n = 0; n < mapsize; n++) {
		
		matrix cov(1,1);
		if (!record[n] && m_map->m_lattices[n].getlabel() > 0) {

			vector<lattice*> closedpiece, openedpiece;
			pieceDetect(m_map->m_lattices + n, closedpiece, openedpiece, cov, record);

			//生成限制向量
			vector<int> restrict;
			for (vector<lattice*>::iterator op = openedpiece.begin(); op<openedpiece.end();op++) {
				restrict.push_back(mineleft[*op - m_map->m_lattices]);
			}

			//计算概率
			vector<float> result;
//			floatProgram(cov, restrict, result);

			//概率实现
			for (int i = 0; i < result.size(); i++) {
				P[closedpiece[i] - m_map->m_lattices] = result[i];
			}
		}
	}
	return 1;
}
//根据剩下雷多少判断概率
int solveMap::finalDetect(){	//复杂度O(n)
	
	int opennumber = 0;

	int relative_cnt = 0;			//有关的
	vector<lattice*> remain;		//剩下的
	for (int n = 0; n < mapsize; n++) {
		if (m_map->m_lattices[n].state == STATE_CLOSED) {
			if (nbopen[n] > 0)relative_cnt++;
			else {
				remain.push_back(m_map->m_lattices + n);
			}
		}
	}
	P = new float[m_map->m_height * m_map->m_width];
	for each(lattice* l in remain) {
		P[l - m_map->m_lattices] = (m_map->m_mineleft - relative_cnt) / remain.size();
	}

	delete[] P;

	if (m_map->m_mineleft == relative_cnt) {
		for each(lattice* l in remain) {
			m_map->Open(l);
		}
		return opennumber;
	}
	else
		return 0;
}
//BFS
int solveMap::ProbExecute()
{
	for (unsigned int n = 0; n < mapsize; n++) {
		if (P[n] == 0) {
			m_map->FastOpen(m_map->m_lattices + n);
		}
		else if (P[n] == 1) {
			m_map->Mark(m_map->m_lattices + n);
		}
	}
	return 1;
}
int solveMap::Solve(int option = 0){
	
	scan();
//	microProb();
//	justOpen();
	while (justOpen()) {
		scan();
	}
//	finalDetect();
	return 1;
}