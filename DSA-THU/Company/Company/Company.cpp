#include <stdio.h>

char buffer[1 << 24];

int F[10000005];
int T[10000005], top = 0;
int code[10000005], counter = 0;

inline bool valid(int r) { return (0 <= r) && (r < top); }
inline bool erased(int a) { return valid(F[a]) && !(T[F[a]] + 1 + a); }
inline bool test(int a) { return valid(F[a]) && (a == T[F[a]]); }

inline void set(int a, int c) {
	code[a] = c;
    if (test(a)) return;
	if (!erased(a)) { 
		F[a] = top++; 
	}
	counter++;
	T[F[a]] = a;
}

inline void clear(int a) {
	if (test(a)) {
		T[F[a]] = -1 - a;
		counter--;
	}
}

inline void close() { top = 0; counter = 0; }

inline int number() { return counter; }
inline int query(int a) {
	if (test(a)) { return code[a]; }
	return -1;
}


void output() {
	printf("top=%d counter=%d\n", top, counter);
	printf("F = ");
	for (int i = 0; i < 11; ++i) {
       printf("%d ", F[i]);
	}
	printf("\n");
	printf("T = ");
	for (int i = 0; i < 11; ++i) {
	    printf("%d ", T[i]);
	}
	printf("\n");
	printf("code = ");
	for (int i = 0; i < 11; ++i) {
	    printf("%d ", code[i]);
	}
	printf("\n");
}

class Bitmap {
private:
	int* F; int N;
	int* T; int top;
protected:
	inline bool valid(int r) { return (0 <= r) && (r < top); }
	inline bool erased(int k) { return valid(F[k]) && !(T[F[k]]+1+k); }
public:
	Bitmap(int n): N(n), top(0) {
	    F = new int[N]; T = new int[N];
	}
	~Bitmap() { delete [] F; delete [] T; }

	inline bool test(int k) {
		return valid(F[k]) && (k == T[F[k]]); 
	}

	inline void set(int k) {
	    if (test(k)) return;
		if (!erased(k)) F[k] = top++;
		T[F[k]] = k;
	}

	inline void clear(int k) {
	    if (test(k)) T[F[k]] = -1 - k;
	}
};

int main() {
	//freopen("in.txt", "r", stdin);
	setvbuf(stdin, buffer, _IOFBF, sizeof(buffer));
    int n, m, a, c, ans = 0;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i) {
		//printf("i=%d ", i);
	    char command[10];
		//getchar();       // 系统原因，用字符串才能AC
		scanf("%s", command);
		switch (command[0]) {
		case 'I': 
			scanf("%d%d", &a, &c);
			//printf("I %d %d\n", a, c);
			set(a, c);
			break;
		case 'O':
			scanf("%d", &a);
			//printf("O %d\n", a);
			clear(a);
			break;
		case 'C':
			//printf("C\n");
			close();
			break;
		case 'N':
		    //printf("N\n"); 
			ans += number();
			break;
		case 'Q':
			scanf("%d", &a);
			//printf("Q %d\n", a);
			ans += query(a);
			break;
		}
		//output();
		//printf("ans = %d\n", ans);
	}

	printf("%d", ans);
	return 0;
}