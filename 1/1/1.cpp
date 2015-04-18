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
#define N 10001

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

	int tb[N];

	int count = 0;
	loop1(i,10000)
	{
		if((i%4 == 0 && i%100 != 0) || (i%400 == 0)) count++;

		tb[i] = count;
	}

	int t;
	RD(t);
	getchar();

	long long start, end;
	char month[15];
	int mm;
	int day;
	long long result = 0;
	loop1(p,t)
	{
		scanf("%s %d, %lld\n",month,&day,&start);

		if(strcmp(month,"January") == 0) mm = 1;
		else if(strcmp(month,"February") == 0) mm = 2;
			 else mm = 3;

		if(mm == 3) start = start+1;
		

		scanf("%s %d, %lld\n",month,&day,&end);
		if(strcmp(month,"January") == 0) mm = 1;
		else if(strcmp(month,"February") == 0) mm = 2;
			 else mm = 3;

		if(mm ==1 || (mm ==2 && day < 29)) end = end-1;

		if(start/10000 == end/10000)
		{
			start = start%10000;
			end = end%10000;
			result = tb[end] - tb[start-1];
		}
		else
		{
			result += tb[end%10000];

			if(end/10000 - start/10000 - 1 > 0) result += (end/10000 - start/10000 - 1)* tb[10000];

			result += (tb[10000] - tb[start%10000 - 1]);
		}


		printf("Case #%d: %lld\n",p,result);


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

