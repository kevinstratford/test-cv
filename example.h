
typedef struct small_s small_t;
typedef struct medium_s medium_t;

struct small_s {
  double data[4];
};

struct medium_s {
  double data[10];
};

int function1(int a);
int function2(void);

int function3(small_t arg);
int function4(medium_t arg);
