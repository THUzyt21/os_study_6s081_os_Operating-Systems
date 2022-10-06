#include "types.h"
#include "user.h"

int main(int argc,char* argv[]){
	int sleep_time;
	if(argc != 2){
		printf(1,"Please Input 2 paras!\n");
		exit();
	}
		sleep_time = atoi(argv[1]);
		sleep(sleep_time);
		printf(1,"Wake Up!\n");
		exit();
}
