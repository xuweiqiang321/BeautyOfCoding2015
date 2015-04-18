/*
注释最好用这种方式。尽量不要用//方式，除非代码特别短。不然粘贴到网页上可能会出错。

代码最后的注释不要删。理由见最后的注释。
*/
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <time.h>
//#define ONLINE_JUDGE


/*
g++: INT_MAX need to be defined.
c++: no need.
*/
//#define GPLUSPLUS
#ifdef ONLINE_JUDGE

	#ifdef GPLUSPLUS
		#define INT_MAX 0x3FFFFFFF
	#endif
#endif

#ifndef ONLINE_JUDGE
	#include<unordered_map>
	#include<unordered_set>
	#include<Windows.h>
	#include<time.h>
#endif

using namespace std;

#define debug(s) puts(s);
#define loop0(i,n) for(int i=0;i<n;i++)
#define loop1(i,n) for(int i=1;i<=n;i++)
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define RD(n) scanf("%d",&n)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define RD4(x,y,z,w) scanf("%d%d%d%d",&x,&y,&z,&w)
#define All(vec) vec.begin(),vec.end()
#define MP make_pair
#define PII pair<int, int>
#define PQ priority_queue
#define cmax(x,y) x = max(x,y)
#define cmin(x,y) x = min(x,y)


#ifndef ONLINE_JUDGE
	typedef struct ListNode 
	{
		  int val;
		  ListNode *next;
		  ListNode(int x) : val(x), next(NULL) {}
	 }ListNode;

	struct treeNode 
	{
		  int val;
		  treeNode *left;
		  treeNode *right;
		  treeNode(int x) : val(x), left(NULL), right(NULL) {}
	 };

	#define LH 1
	#define EH 0
	#define RH -1
	typedef struct avlNode
	{
		int val;
		int bf;
		struct avlNode * left, * right;

	}avlNode, * avlTree;

	struct Point {
		  int x;
		  int y;
		  Point() : x(0), y(0) {}
		  Point(int a, int b) : x(a), y(b) {}
	 };

	#define ENDCHILD 0
	#define ENDSYMBOL -1

	typedef treeNode * Tree;
	typedef int Elemtype;


	template <typename T> T  constructBtree(void);
	template <typename T> void inorder_core(const T& root);
	template <typename T> void preorder_core(const T& root);
	template <typename T> void inorder(const T& root);
	template <typename T> void preorder(const T& root);
	template <typename T> void freeTree(const T& root);
	template <typename T> void checkTree(const T& root);

	template <typename T> void R_Rotate(T &p);
	template <typename T> void L_Rotate(T &p);
	template <typename T> bool InsertAVL(T& avlroot, int e, bool & taller);
	template <typename T> void LeftBalance(T &avlroot);
	template <typename T> void RightBalance(T &avlroot);
#endif

/*注意模板*/
/*
*由于模板原因，不要定义#define T
*
*/
#define INF 1e50
#define RAD 10000
#define eps 1e-8

typedef struct point
{
	double x;
	double y;
	double dist;
	point(){}
	point(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
	
}point;

point as[1005];
point bs[105];


double pi=acos(-1.0);

int n,m,a,b;

const int nm=15;   //初始解空间大小
const int nmf=25;  //扩展解空间大小

point q[nm];
double dist(point a, point b)
{
    return (a.x - b.x)*(a.x - b.x)*1.0 + (a.y - b.y)*(a.y - b.y)*1.0;
}
double get(point p)
{
    double sum = 0;
    loop0(i,a) sum += dist(p,as[i]);

	double mht = INF;

	loop0(i,b)
		if((fabs(bs[i].x - p.x) + fabs(bs[i].y - p.y)) < mht) mht = fabs(bs[i].x - p.x) + fabs(bs[i].y - p.y);

	sum += mht;
    return sum;
}

double Rand(){return rand()%(RAD+1)/(1.0*RAD);}//随机产生0-1的浮点数  
point Rand_point(point a,point b)//在a,b框定的四边形内随机生成点  
{  
    double xx=a.x+(b.x-a.x)*Rand();  
    double  yy=a.y+(b.y-a.y)*Rand();  
    point tmp=point(xx,yy);  
	tmp.dist = get(tmp); 
    return tmp;  
}

int main()
{
#ifndef ONLINE_JUDGE
	/*只需要修改num数组，其他不要动*/
	char num[3] = "";

	char in[20] = "test data/ye.in";
	char out[20] = "test data/ye.out";

	for(int i=0;i<strlen(num);i++) in[strlen(in) + i] = num[i];
	for(int i=0;i<strlen(num);i++) out[strlen(out) + i] = num[i];

	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
#endif
	srand((unsigned)time(NULL));  //多次提交= =防RP差
    int ca;
	int x,y;
	double nn,mm;
    scanf("%d",&ca);
	int mx;
    for(int p=1;p<=ca;p++)
    {
        RD4(n,m,a,b);
        
		nn = n;
		mm = m;
		mx = max(n,m);
		loop0(i,a)
		{
			RD2(x,y);
			as[i].x = x;
			as[i].y = y;
		}
		loop0(i,b)
		{
			RD2(x,y);
			bs[i].x = x;
			bs[i].y = y;
		}
		//构造初始解空间
		q[0].x = 1;
		q[0].y = 1;
		q[1].x = n;
		q[1].y = m;
		q[2].x = 1;
		q[2].y = m;
		q[3].x = n;
		q[3].y = 1;

		q[0].dist = get(point(q[0].x, q[0].y));
		q[1].dist = get(point(q[1].x, q[1].y));
		q[2].dist = get(point(q[2].x, q[2].y));
		q[3].dist = get(point(q[3].x, q[3].y));
        for(int i=4;i<nm;i++) //构造初始解空间
        {
            q[i] = Rand_point(q[0],q[1]);
        }
        double dd= mx;     //最大温度
		double now, t;
        while(dd>1e-2)
        {
            loop0(i,nm)
            {
				now=q[i].dist;
                loop0(j,nmf)
                {
                    double dt=Rand()*2*pi;      //随机角度
                    point tmp=Rand_point(point(max(1.0,q[i].x-dd),max(1.0,q[i].y-dd)),point(min(nn,q[i].x+dd),min(mm,q[i].y+dd)));  
                    
					//if((tmp.x-1)<-eps||(tmp.x-nn)>eps||(tmp.y-1)<-eps||(tmp.y-mm)>eps) continue;

					t=tmp.dist;
                    if((t-now)<-eps) //扩展新解
                    {
                        q[i].x=tmp.x;
                        q[i].y=tmp.y;

						//printf("tmpx: %f   tmpy:%f\n",tmp.x,tmp.y);
						q[i].dist = t;
                        now=t;
                    }
					/*
					else //以一定概率容纳错误解
					{
						if((exp((now - t)/dd))>Rand())
						{
							
							q[i].x=tmp.x;
							q[i].y=tmp.y;

							//printf("tmp.x: %f   tmp.y:%f       be careful\n",tmp.x,tmp.y);
							q[i].dist = t;
							now=t;
						}
					}
					*/
					
                }
            }
            dd*=0.8;            //冷却速度
        }

        double mins=INF;
        int k;
        loop0(i,nm)
        {
            double tmp=q[i].dist;
            if(tmp<mins)
			{
				mins=tmp;
				k = i;
			}
        }

		int dst_x = (int)(q[k].x + 0.5);
		int dst_y = (int)(q[k].y + 0.5);


		
		//printf("Case #%d: %.2f      x:%f  y:%f     ",p,mins,q[k].x, q[k].y);
		printf("Case #%d: %lld\n",p,(long long)get(point(dst_x, dst_y)));
    }
	/*
	Tree root = constructBtree<Tree>();
	checkTree<Tree>(root);
	freeTree<Tree>(root);
	

	avlTree  avlroot = NULL;
	bool taller = false;
	InsertAVL<avlTree>(avlroot, 20, taller);
	InsertAVL<avlTree>(avlroot, 10, taller);
	InsertAVL<avlTree>(avlroot, 40, taller);
	InsertAVL<avlTree>(avlroot, 30, taller);
	InsertAVL<avlTree>(avlroot, 35, taller);
	checkTree<avlTree>(avlroot);
	freeTree<avlTree>(avlroot);
	*/
	// TO DO










#ifndef ONLINE_JUDGE
	getchar();
	getchar();
#endif

	return 0;
}

#ifndef ONLINE_JUDGE

	template <typename T> T  constructBtree(void)
	{
		T root,now,t;
		T maxLayer[256];
		Elemtype n;
		int count = 0, beingused = 0;
    
		now = (T)malloc(sizeof(treeNode));
		maxLayer[count++] = now;
    
		root = now;
    
		scanf("%d",&(root->val));
    
		scanf("%d", &n);
		while(n != ENDSYMBOL)
		{
				if(n != ENDCHILD)
				{
					 now = (T)malloc(sizeof(treeNode));
					 maxLayer[count++] = now;
					 now->val = n;
					 maxLayer[beingused]->left = now;
                 
                 
				}
				else
				{
					maxLayer[beingused]->left = NULL;
                
                
				}
            
				scanf("%d", &n);
				if(n != ENDCHILD)
				{
					 now = (T)malloc(sizeof(treeNode));
					 maxLayer[count++] = now;
					 now->val = n;
					 maxLayer[beingused]->right = now;
                 
                 
				}
				else
				{
					maxLayer[beingused]->right = NULL;
                
                
				}
            
				beingused++;
				scanf("%d", &n);
                  
		}

		return root;
	}

	template <typename T> void inorder_core(const T& root)
	{
		 if(!root) return;
     
		 inorder_core(root->left);
		 printf("%d ", root->val);
		 inorder_core(root->right);
	} 

	template <typename T> void preorder_core(const T& root)
	{
		 if(!root) return;
     
		 printf("%d ", root->val);
		 preorder_core(root->left);
		 preorder_core(root->right);
	} 

	template <typename T> void inorder(const T& root)
	{
		printf("inorder: ");
		inorder_core(root);
		printf("\n");
	}

	template <typename T> void preorder(const T& root)
	{
		printf("preorder: ");
		preorder_core(root);
		printf("\n");
	}

	template <typename T> void freeTree(const T& root)
	{
		if(root == NULL) return;

		freeTree(root->left);
		freeTree(root->right);
		free(root);//free完了之后，并不表示root就成了null。这个程序我只想说这一句。
	}

	template <typename T> void checkTree(const T& root)
	{
		inorder(root);
		preorder(root);
	}

	template <typename T> void R_Rotate(T &p)
	{
		T lc = p->left;
		p->left = lc->right;
		lc->right = p;
		p = lc;
	}

	template <typename T> void L_Rotate(T &p)
	{
		T rc = p->right;
		p->right = rc->left;
		rc->left = p;
		p = rc;
	}

	template <typename T> void LeftBalance(T &avlroot)
	{
		T lc = avlroot->left;

		switch(lc->bf)
		{
			case LH:
				avlroot->bf = lc->bf = EH;
				R_Rotate(avlroot); 
				break;
			case RH:
				T rd = lc->right;
				switch(rd->bf)
				{
					case LH: avlroot->bf = RH; lc->bf = EH; break;
					case EH: avlroot->bf = lc->bf = EH; break;
					case RH: avlroot->bf = EH; lc->bf = LH; break;
				}
				rd->bf = EH;
				L_Rotate(avlroot->left);
				R_Rotate(avlroot);
		}
	}

	template <typename T> void RightBalance(T &avlroot)
	{
		T rc = avlroot->right;

		switch(rc->bf)
		{
			case RH:
				avlroot->bf = rc->bf = EH;
				R_Rotate(avlroot); 
				break;
			case LH:
				T ld = rc->left;
				switch(ld->bf)
				{
					case LH: avlroot->bf = RH; rc->bf = EH; break;
					case EH: avlroot->bf = rc->bf = EH; break;
					case RH: avlroot->bf = EH; rc->bf = LH; break;
				}
				ld->bf = EH;
				R_Rotate(avlroot->right);
				L_Rotate(avlroot);
		}
	}

	template <typename T> bool InsertAVL(T& avlroot, int e, bool & taller)
	{
		if(!avlroot)
		{
			avlroot = (T )malloc(sizeof(avlNode));
			avlroot->val = e;
			avlroot->left = avlroot->right = NULL;
			avlroot->bf = EH;
			taller = true;
		}
		else
		{
			if(e == avlroot->val)
			{
				taller = false;
				return false;
			}
		
			if(e < avlroot->val)
			{
				if(!InsertAVL(avlroot->left,e,taller)) return false;

				if(taller)
				{
					switch(avlroot->bf)
					{
						case LH:
							LeftBalance(avlroot);
							taller = false;
							break;
						case EH:
							avlroot->bf = LH;
							taller = true;
							break;
						case RH:
							avlroot->bf = EH;
							taller = false;
							break;
					}
				}
			}
			else
			{
				if(!InsertAVL(avlroot->right,e,taller)) return false;

				if(taller)
				{
					switch(avlroot->bf)
					{
						case LH:
							avlroot->bf = EH;
							taller = false;
							break;
						case EH:
							avlroot->bf = RH;
							taller = true;
							break;
						case RH:
							RightBalance(avlroot);
							taller = false;
							break;
					}
				}
			}
		}

		return true;
	}
#endif

/*
对于一些OJ来说，最后的空行是不可或缺的。
*/

