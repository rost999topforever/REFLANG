#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
/* constans */
#define TEXT_LEN 1024
#define MAX_ARGS 512
int compil=0;
int forever=0;
int rep_start=0;
int rep_times=0;
int rep=0;
char var[TEXT_LEN][TEXT_LEN];
char var_name[TEXT_LEN][TEXT_LEN];
int var_counter=0;
char *save_part=NULL;
char ptr[TEXT_LEN];
char  buf[TEXT_LEN];
char  text[TEXT_LEN];
int comand_counter=0;
char *comand[MAX_ARGS];
/* end of constans */

/* my functions */
void cmd_printf(char *a){
	printf("%s",a);
}
void cmd_space(void){
	printf(" ");
}
void cmd_buf(char *a){
	strcpy(buf,a);
}
void cmd_print(char *a){
	if(strcmp(a,"$")==0){
		printf("%s",buf);
	}else if(strcmp(a,"*")==0){
		printf("%s",ptr);
	}else{
		printf("%s",a);
	}
}
void cmd_endl(void){
	printf("\n");
}
void cmd_get(void){
	fgets(buf,sizeof(buf),stdin);
	buf[strcspn(buf,"\n")]=0;
}
void cmd_var(char *a){
	strcpy(var[var_counter],buf);
	strcpy(var_name[var_counter],a);
	var_counter+=1;
}
void cmd_getin(char *a){
	for(int vars=0;vars<var_counter;vars++){
		if(strcmp(var_name[vars],a)==0){
			strcpy(buf,var[vars]);
		}
	}
}
void cmd_exo(char *a){
	if(strcmp(a,"$")==0){
		printf("%s ",buf);
	}else if(strcmp(a,"*")==0){
		printf("%s ",ptr);
	}else{
		printf("%s ",a);
	}
}
void cmd_println(char *a){
	if(strcmp(a,"$")==0){
		printf("%s\n",buf);
	}else if(strcmp(a,"*")==0){
		printf("%s\n",ptr);
	}else{
		printf("%s\n",a);
	}
}
void cmd_ptr(char *a){
	for(int vars=0;vars<var_counter;vars++){
		if(strcmp(var_name[vars],a)==0){
			strcpy(ptr,var[vars]);
		}
	}
}
void cmd_add(char *a){
	if(atoi(a)!=0){
	sprintf(buf,"%d",(atoi(buf)+atoi(a)));
	}else{
		for(int vars=0;vars<var_counter;vars++){
			if(strcmp(var_name[vars],a)==0){
				sprintf(buf,"%d",(atoi(buf)+atoi(var[vars])));
			}
		}
	}
}
void cmd_mul(char *a){
	if(atoi(a)!=0){
	sprintf(buf,"%d",(atoi(buf)*atoi(a)));
	}else{
		for(int vars=0;vars<var_counter;vars++){
			if(strcmp(var_name[vars],a)==0){
				sprintf(buf,"%d",(atoi(buf)*atoi(var[vars])));
			}
		}
	}
}
void cmd_div(char *a){
	if(atoi(a)!=0){
	sprintf(buf,"%d",(atoi(buf)/atoi(a)));
	}else if(strcmp(a,"0")==0){
		printf("ERR::not zero\n");
	}else{
		for(int vars=0;vars<var_counter;vars++){
			if(strcmp(var_name[vars],a)==0){
				sprintf(buf,"%d",(atoi(buf)+atoi(var[vars])));
			}
		}
	}
}
void cmd_time(void){
	sprintf(buf,"%ld",time(NULL));
}
void cmd_nom(char *a, char *b, char *c){
		if(strcmp(b,"=")==0){
			if(atoi(a)==atoi(c)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
	else if(strcmp(b,"<")==0){
			if(atoi(a)<atoi(c)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
	else if(strcmp(b,"<=")==0){
			if(atoi(a)<=atoi(c)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
	else if(strcmp(b,">")==0){
			if(atoi(a)>atoi(c)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
	else if(strcmp(b,">=")==0){
			if(atoi(a)>=atoi(c)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"$==*")==0){
			if(strcmp(buf,ptr)==0){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"$<*")==0){
			if(atoi(buf)<atoi(ptr)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"$<=*")==0){
			if(atoi(buf)<=atoi(ptr)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"$>*")==0){
			if(atoi(buf)>atoi(ptr)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"$>=*")==0){
			if(atoi(buf)>=atoi(ptr)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"*==$")==0){
			if(strcmp(ptr,buf)==0){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"*<$")==0){
			if(atoi(ptr)<atoi(buf)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"*<=$")==0){
			if(atoi(ptr)<=atoi(buf)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"*>$")==0){
			if(atoi(ptr)>atoi(buf)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"*>=$")==0){
			if(atoi(ptr)>=atoi(buf)){
				strcpy(buf,"1");
			}else{
				strcpy(buf,"0");
			}
		}
		else if(strcmp(b,"*to$")==0){
			if(atoi(a)==atoi(c)){
			sprintf(buf,"%d",((atoi(buf)-atoi(ptr))/atoi(a)));
			}
		}
		else if(strcmp(b,"$to*")==0){
			if(atoi(a)==atoi(c)){
			sprintf(buf,"%d",((atoi(ptr)-atoi(buf))/atoi(a)));
			}
		}
		
	}
void cmd_rand(char *a , char *b){
	sprintf(buf,"%d",(atoi(a)+rand()%(atoi(b)-atoi(a)+1)));
}
void cmd_srand(void){
	sprintf(buf,"%d",(atoi(buf)+rand()%(atoi(ptr)-atoi(buf)+1)));
}
void cmd_end(void){
	rep=0;
	rep_times=0;
	forever=0;
}
void cmd_forever(void){
	forever=1;
}
void cmd_fileget(char *a){
	char ftext[TEXT_LEN];
	FILE *f=fopen(a,"r");
	strcpy(buf,"");
	while(fgets(ftext,sizeof(ftext),f)){
		strcat(buf,ftext);
	}
	fclose(f);
}
void cmd_filewrite(char *a){
	FILE *f=fopen(a,"w+");
	fprintf(f,"%s",buf);
	fclose(f);
}
void cmd_fileadd(char *a){
	FILE *f=fopen(a,"a+");
	fprintf(f,"%s",buf);
	fclose(f);
}
void cmd_syscomand(void){
	system(buf);
}
void cmd_open(char *a){
	execlp(a,a,NULL);
}
void cmd_exit(void){
	exit(0);
}
void cmd_getpwd(void){
	getcwd(buf,sizeof(buf));
}
void cmd_chdir(void){
	if(buf!=NULL){
	chdir(buf);
	}
}
void cmd_list(void){
	DIR *dir=opendir(".");
	struct dirent *entry;
	while((entry=readdir(dir))!=NULL){
		printf("%s  ",entry->d_name);
	}
	printf("\n");
	closedir(dir);
}
void cmd_len(void){
	sprintf(buf,"%d",strlen(buf));
	
}
void cmd_free(char *a){
	for(int vars=0;vars<var_counter;vars++){
		if(strcmp(var_name[vars],a)==0){
			strcpy(var[vars],"");
			strcpy(var_name[vars],"");
		}
	}
}
void cmd_printall(void){
	for(int vars=0;vars<var_counter;vars++){
		printf("%s-%s\n",var_name[vars],var[vars]);
	}
}
void cmd_fork(void){
	fork();
}
void cmd_addtobuf(char *a){
	strcat(buf,a);
}

/* end of my functions */

int main(int argc, char *argv[])
{ 
srand(time(NULL));
printf("REFLANG-by rost999topforever\n");
/* REPL starts */
while(1){
	/* skip or conrinue*/
	if(argc<2){
	strcpy(text,"");
	comand_counter=0;
	printf(")]}>");
	fgets(text,sizeof(text),stdin);
	text[strcspn(text,"\n")]=0;
	}else{
		comand_counter=0;
		compil+=1;
		strcpy(text,"");
		FILE *f=fopen(argv[1],"r");
		while(fgets(buf,sizeof(buf),f)){
			strcat(text,buf);
			text[strcspn(text,"\n")]=0;
			strcat(text," ");
		}
		fclose(f);
		strcpy(buf,"");
	}
	/* NULL checer */
	if(text==NULL){
		continue;
	}
	/* end of NULL checer */
	/* parsing */
	if(text[0]!='\0'){
	comand[comand_counter]=strtok_r(text," ",&save_part);
	comand_counter+=1;
	while(comand[comand_counter]=strtok_r(NULL," ",&save_part)){
		comand_counter+=1;
	}
	comand[comand_counter]=0;
	}
	/* end of parsing */
	/* start of main loop */
	for(int now=0;now<comand_counter;now+=1){
		if(strcmp(comand[now],"printf")==0 && comand[now+1]!=NULL){
			cmd_printf(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
		else if(strcmp(comand[now],"//space//")==0){
			cmd_space();
		}
		else if((strcmp(comand[now],"buf")==0 || strcmp(comand[now],"bvar")==0)&& comand[now+1]!=NULL){
			cmd_buf(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
		else if(strcmp(comand[now],"print")==0 && comand[now+1]!=NULL){
			cmd_print(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"//endl//")==0){
			cmd_endl();
	}
	else if(strcmp(comand[now],"get")==0){
			cmd_get();
	}
	else if(strcmp(comand[now],"var")==0 && comand[now+1]!=NULL){
			cmd_var(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"getin")==0 && comand[now+1]!=NULL){
			cmd_getin(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
  else if((strcmp(comand[now],"echo")==0 || strcmp(comand[now],"exo")==0)&& comand[now+1]!=NULL){
			cmd_exo(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
    else if(strcmp(comand[now],"println")==0 && comand[now+1]!=NULL){
			cmd_println(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
     else if((strcmp(comand[now],"ptr")==0 || strcmp(comand[now],"*ptr")==0)&& comand[now+1]!=NULL){
			cmd_ptr(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"add")==0 && comand[now+1]!=NULL){
			cmd_add(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"mul")==0 && comand[now+1]!=NULL){
			cmd_mul(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"div")==0 && comand[now+1]!=NULL){
			cmd_div(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"time")==0){
			cmd_time();
	}
	else if(strcmp(comand[now],"con")==0 && comand[now+1]!=NULL && comand[now+2]!=NULL && comand[now+3]!=NULL){
			cmd_nom(comand[now+1],comand[now+2],comand[now+3]);
			if(now+3<comand_counter){
				now+=3;
			}
		}
else if(strcmp(comand[now],"rand")==0 && comand[now+1]!=NULL && comand[now+2]!=NULL){
			cmd_rand(comand[now+1],comand[now+2]);
			if(now+2<comand_counter){
				now+=2;
			}
		}
else if(strcmp(comand[now],"srand")==0||strcmp(comand[now],"$rand*")==0){
			cmd_srand();
	}
	/* sorry my code style */
	else if(strcmp(comand[now],"if")==0){
			if(atoi(buf)==1){
		;
	}else{
		break;
	}
	}
	else if(strcmp(comand[now],"else")==0){
			if(atoi(buf)==0){
		;
	}else{
		break;
	}
	}
	else if(strcmp(comand[now],"repeat")==0 && comand[now+1]!=NULL){
		if(rep==0 && rep_times==0){
		rep_times=atoi(buf)+1;
		rep_start=now+1;
		rep=atoi(comand[now+1]);
		strcpy(buf,"0");
		now+=rep;
		}
	} 
	/* end of hell */
	else if(strcmp(comand[now],"forever")==0){
			cmd_forever();
	}
	else if(strcmp(comand[now],"end")==0){
			cmd_end();
	}
	else if(strcmp(comand[now],"fileget")==0 && comand[now+1]!=NULL){
			cmd_fileget(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"filewrite")==0 && comand[now+1]!=NULL){
			cmd_filewrite(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"fileadd")==0 && comand[now+1]!=NULL){
			cmd_fileadd(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
		else if(strcmp(comand[now],"exit")==0){
			cmd_exit();
	}
	else if(strcmp(comand[now],"syscomand")==0){
			cmd_syscomand();
	}
	else if(strcmp(comand[now],"open")==0 && comand[now+1]!=NULL){
			cmd_open(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
		else if(strcmp(comand[now],"getpwd")==0){
			cmd_getpwd();
	}
	else if(strcmp(comand[now],"list")==0){
			cmd_list();
	}
	else if(strcmp(comand[now],"chdir")==0){
			cmd_chdir();
		}
	else if(strcmp(comand[now],"len")==0){
			cmd_len();
		}
		else if(strcmp(comand[now],"free")==0 && comand[now+1]!=NULL){
			cmd_free(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
	else if(strcmp(comand[now],"print_all_vars")==0){
			cmd_printall();
		}
	else if(strcmp(comand[now],"fork")==0){
			cmd_fork();
		}
	else if(strcmp(comand[now],"addtobuf")==0 && comand[now+1]!=NULL){
			cmd_addtobuf(comand[now+1]);
			if(now+1<comand_counter){
				now+=1;
			}
		}
		else if(strcmp(comand[now],"class")==0 && comand[now+1]!=NULL && comand[now+2]!=NULL){
		    for(int start=now+3;start<(now+atoi(comand[now+2]))*2;start+=1){
		    	if(comand[start]!=NULL && comand[start+1]!=NULL){
		    		sprintf(var_name[var_counter],"%s.%s",comand[now+1],comand[start]);
		    		sprintf(var[var_counter],"%s",comand[start+1]);
		    		var_counter+=1;
		    		start+=1;
		    	}
		    }
		    
		}
	/* end of for loop */
	if(forever==1){
		if(now==rep_start+rep){
		now=rep_start;
		}
	}
	if((rep_times>0 && now== rep_start+rep)){
		rep_times-=1;
		if(rep_times>0){
			now=rep_start;
		}else{
			rep_start=0;
			rep_times=0;
			rep=0;
		}
	}
	
	}
	/* end of main loop */
	if(compil==1){
		exit(0);
	}
}
/* end of all program */
	return 0;
}