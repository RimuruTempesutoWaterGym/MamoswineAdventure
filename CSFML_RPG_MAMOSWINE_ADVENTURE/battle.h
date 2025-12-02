typedef struct {

	char name[30];
	Attack attacks[4];
	int stats[6];
	
	Types type[2];
} pokemon;
typedef struct {
	int id;
	char name[20];
	int power;
	int accuracy;
	int priority;
	int type;
} Attack;

typedef enum {
	null,Normal,ground,ice,grass,fire,combat,fairy,water,electric,steel,dragon,bug,ghost,dark,psy,fly,rock,poison
} Types;