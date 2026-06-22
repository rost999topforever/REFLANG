#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#define input 1
int main(int argc, char *argv[])
{
	int e=0;
	int sav,savv,savvv,svv;
	char file_buf[999];
	srand(time(NULL));
	int cmd_count=0;
	char file[999];
	int r=0;
	char ptr[999];
	int rep=0;
	int sb=0;
	char varname[999][99];
	char vars[999][999];
	int varc=0;
	char buf[999];
	int comand_counter=0;
	char text[999];
	char *comand[9999];
	char *s;
	if(2>argc|| input==1){
		printf("REFLANG by rost999topforever\n");
		while(1){
			er:
			if(rep<=0 || argc<2){
			printf("])}>");
			fgets(text,sizeof(text),stdin);
			text[strcspn(text,"\n")]=0;
			comand_counter=0;
			if((text[0]=='\0')){
				continue;
			}
			}
			s=NULL;
			comand[comand_counter]=strtok_r(text," ",&s);
			comand_counter++;
			while(comand[comand_counter]=strtok_r(NULL," ",&s)){
				comand_counter++;
			}
			interp:
			for(int now=0;now<comand_counter;now++){
				if(strcmp(comand[now],"print")==0){
					if(comand[now+1]!=0){
					if(strcmp(comand[now+1],"$")!=0){
					printf("%s",comand[now+1]);
					if(now+1<=comand_counter){
					now++;
					}
					}else{
						printf("%s",buf);
						if(now+1!=comand_counter){
					now++;
					}
					}
					}
				}
				if(strcmp(comand[now],"//endl//")==0){
					printf("\n");
					
				}
				if(strcmp(comand[now],"get")==0){
					fgets(buf,sizeof(buf),stdin);
					buf[strcspn(buf,"\n")]=0;
					}
				if(strcmp(comand[now],"bvar")==0||strcmp(comand[now],"buf")==0){
					if(comand[now+1]!=0){
						strcpy(buf,comand[now+1]);
						now+=1;
					}
				}
				if(strcmp(comand[now],"time")==0){
					sprintf(buf,"%d",time(NULL));
					
				}
				if(strcmp(comand[now],"var")==0){
					if(comand[now+1]!=NULL){
					strcpy(vars[varc],buf);
					strcpy(varname[varc],comand[now+1]);
					varc++;
					if(now+1!=comand_counter){
						now++;
					}
					}
					}
					if(strcmp(comand[now],"getin")==0){
						if(comand[now+1]!=0){
							for(int nom=0;nom<varc;nom++){
								if(strcmp(varname[nom],comand[now+1])==0){
									strcpy(buf,vars[nom]);
									if(now+1!=comand_counter){
										now++;
									}
								}
							}
							}
						}
						if(strcmp(comand[now],"printf")==0){
							if(comand[now+1]!=0){
							printf("%s",comand[now+1]);
							if(now+1!=comand_counter){
								now++;
							}
							}
						}
						if(strcmp(comand[now],"add")==0){
							if(comand[now+1]!=0){
								sb=atoi(buf);
								sb=sb+(atoi(comand[now+1]));
								sprintf(buf,"%d",sb);
								if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"if")==0){
							
								if(atoi(buf)==1){
									;
								}else{
									goto er;
								}
							
						}
						if(strcmp(comand[now],"$=")==0){
						if(comand[now+1]!=0){	if(atoi(buf)==atoi(comand[now+1])){
							
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
							}
						}
						if(strcmp(comand[now],"$<")==0){
							if(comand[now+1]!=0){
							if(atoi(buf)<atoi(comand[now+1])){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
							}
						}
						if(strcmp(comand[now],"$>")==0){
							if(comand[now+1]!=0){
							if(atoi(buf)>atoi(comand[now+1])){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
							}
						}
						if(strcmp(comand[now],"$>=")==0){
							if(comand[now+1]!=0){
							if(atoi(buf)>=atoi(comand[now+1])){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
							}
						}
						if(strcmp(comand[now],"$<=")==0){
							if(comand[now+1]!=0){
							if(atoi(buf)<=atoi(comand[now+1])){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
							}
						}
						if(strcmp(comand[now],"*ptr")==0||strcmp(comand[now],"ptr")==0){
							if(comand[now+1]!=0){
								for(int o=0;o<varc;o++){
									if(strcmp(comand[now+1],varname[o])==0){
										sprintf(ptr,"%s",vars[o]);
										
									}
								}
								if(now+1!=comand_counter){
											now++;
										}
							}
						}
						if(strcmp(comand[now],"$=*")==0){
							if(atoi(buf)==atoi(ptr)){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
						}
						if(strcmp(comand[now],"$<*")==0){
							if(atoi(buf)<atoi(ptr)){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
						}
						if(strcmp(comand[now],"$>*")==0){
							if(atoi(buf)>atoi(ptr)){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
						}
						if(strcmp(comand[now],"$>=*")==0){
							
							if(atoi(buf)>=atoi(ptr)){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
							
						}
						if(strcmp(comand[now],"$<=*")==0){
							
							if(atoi(buf)<=atoi(ptr)){
								sprintf(buf,"1");
							}else{
								sprintf(buf,"0");
							}
							
						}
						if(strcmp(comand[now],"//space//")==0){
							printf(" ");
							if(now+1!=comand_counter){
								now++;
							}
						}
						if(strcmp(comand[now],"mul")==0){
							if(comand[now+1]!=0){
								sb=0;
								sb=atoi(buf)*atoi(comand[now+1]);
								sprintf(buf,"%d",sb);
								if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"div")==0){
							if(comand[now+1]!=0){
								sb=0;
								sb=atoi(buf)/atoi(comand[now+1]);
								sprintf(buf,"%d",sb);
								if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"else")==0){
							
								if(atoi(buf)==0){
									;
								}else{
									goto er;
								}
							
						}
						if(strcmp(comand[now],"repeat")==0){
							if(rep==0 && r==0){
							cmd_count=0;
                          for (int i = 0; i < comand_counter && strcmp(comand[i],"wall")!=0; i++) {
                          if ( comand[i] != NULL) {
                          cmd_count++;
                           }
                           }
                            rep = atoi(buf) * (cmd_count + 2);
							sprintf(buf,"%d",0);
							r++;
							}
							if(rep==0 && r==1){
								r=0;
							}
						}
						if(strcmp(comand[now],"connect*")==0){
							strcat(buf,ptr);
						}
						if(strcmp(comand[now],"getlen")==0){
							sprintf(buf,"%d",strlen(buf));
						}
						if(strcmp(comand[now],"$==*")==0){
							if(strcmp(buf,ptr)==0){
								sprintf(buf,"%d",1);
							}else{
									sprintf(buf,"%d",0);
							}
						}
						if(strcmp(comand[now],"end")==0){
							rep=0;
							r=0;
							e=0;
						}
						if(strcmp(comand[now],"wall")==0){
							if(r==1){
								while(now>=1){
									now--;
								}
								if(e==0){
								rep/=cmd_count;
								}
								if(rep<=0 && r==1){
									r=0;
								}
							}
						}
						if(strcmp(comand[now],"srng")==0){
							sprintf(buf,"%d",(rand()%(atoi(buf)+1)));
						}
						if(strcmp(comand[now],"rng")==0){
							if(comand[now+1]!=NULL){
								sprintf(buf,"%d",(atoi(buf)+(rand()%(atoi(comand[now+1])-atoi(buf)+1))));
								if((now+1)!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"rand")==0){
							sprintf(buf,"%d",rand());
						}
						if(strcmp(comand[now],"random")==0){
							sprintf(buf,"%d",rand()%2);
						}
						if(strcmp(comand[now],"fileget")==0){
							if(comand[now+1]!=NULL){
								FILE *f=fopen(comand[now+1],"r+");
								strcpy(buf,"");
								while(fgets(file_buf,sizeof(file_buf),f)){
									strcat(buf,file_buf);
								}
								fclose(f);
								if(now+1!=comand_counter){
									now++;
								}
								
							}
						}
						if(strcmp(comand[now],"filewrite")==0){
								if(comand[now+1]!=NULL){
								FILE *f=fopen(comand[now+1],"w+");
								fprintf(f,"%s",buf);
								fclose(f);
								if(now+1!=comand_counter){
									now++;
								}
								}
						}
						if(strcmp(comand[now],"fileadd")==0){
								if(comand[now+1]!=NULL){
								FILE *f=fopen(comand[now+1],"a+");
								fprintf(f,"%s",buf);
								fclose(f);
								if(now+1!=comand_counter){
									now++;
								}
								}
						}
						
						if(strcmp(comand[now],"binget")==0){
							if(comand[now+1]!=NULL){
								FILE *f=fopen(comand[now+1],"rb+");
								strcpy(buf,"");
								while(fgets(file_buf,sizeof(file_buf),f)){
									strcat(buf,file_buf);
								}
								fclose(f);
								if(now+1!=comand_counter){
									now++;
								}
								
							}
						}
						if(strcmp(comand[now],"fileremove")==0){
						if(comand[now+1]!=NULL){
							remove(comand[now+1]);
						}
						if(now+1!=comand_counter){
							now++;
						}
						}
						if(strcmp(comand[now],"changedir")==0){
							if(comand[now+1]!=NULL){
								chdir(comand[now+1]);
								if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"getpwd")==0){
							getcwd(buf,sizeof(buf));
						}
						if(strcmp(comand[now],"list")==0){
							DIR *dir=opendir(".");
							struct dirent *entry=0;
							while((entry=readdir(dir))!=NULL){
								printf("%s\n",entry->d_name);
							}
							closedir(dir);
						}
						if(strcmp(comand[now],"*to$")==0){
							if(comand[now+1]!=NULL){
								sav=atoi(ptr);
								savv=atoi(buf);
								savvv=atoi(comand[now+1]);
								if((((sav - savv) < 0) && (savvv > 0)) || ((sav - savv) > 0) && (savvv < 0)){
									printf("err:infinity steps\n");
									goto er;
								}
								while(sav!=savv){
									sav+=savvv;
									svv+=1;
								}
								sprintf(buf,"%d",svv);
								if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"//*//")==0){
							printf("%s",ptr);
						}
						if(strcmp(comand[now],"echo")==0){
							if(comand[now+1]!=NULL){
							printf("%s ",comand[now+1]);
							if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"open")==0){
							if(comand[now+1]!=NULL){
								execlp(comand[now+1],comand[now+1],NULL);
								if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"syscomand")==0){
							system(buf);
						}
						if(strcmp(comand[now],"sleep")==0){
							if(comand[now+1]!=NULL){
							sav=time(NULL)+atoi(comand[now+1]);
							while(time(NULL)!=sav){
								;
							}
				         	if(now+1!=comand_counter){
									now++;
								}
							}
						}
						if(strcmp(comand[now],"fork")==0){
							fork();
						}
		                if(strcmp(comand[now],"forever")==0){
		                	e=1;
		                }
		                
		
		
		
		
		
						if(rep>0 && e==0){
							rep-=1;
						}
							
				
				
			}
		
		}
	}else{
		FILE *f=fopen(argv[1],"r");
		while(fgets(file,sizeof(file),f)){
			strcat(text,file);
		}
		fclose(f);
		goto interp;
	}
	return 0;
}