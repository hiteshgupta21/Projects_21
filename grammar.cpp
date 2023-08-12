

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove extra dots
void dot_remov(char *str, char ch) {
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++) {
        if (str[i] == ch && (i == 0 || str[i - 1] != ch)) {
            str[j++] = str[i];
        } else if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to remove extra commas
void comma_remov(char *str, char ch) {
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++) {
        if (str[i] == ch && (i == 0 || str[i - 1] != ch)) {
            str[j++] = str[i];
        } else if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to remove extra spaces
void space_remov(char *str, char ch) {
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++) {
        if (str[i] == ch && (i == 0 || str[i - 1] != ch)) {
            str[j++] = str[i];
        } else if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to capitalize letters after a specific character
void uppercase(char *str, char ch) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch && str[i + 1] >= 'a' && str[i + 1] <= 'z') {
            str[i + 1] = str[i + 1] - 'a' + 'A';
        }
    }
}

// Function to convert 'i' to 'I'
void i_I_conv(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'i' && (i == 0 || str[i - 1] == ' ' || str[i - 1] == '.' || str[i - 1] == ',')) {
            str[i] = 'I';
        }
    }
}

int main() {
    printf("*******************WELCOME TO THE TEXT CORRECTION*******************\n\n\n");

    char ch, ch1, *p, input[100], output[100], ch2;
    int op, c = 0, j = 0, i = 0, i_max = 0; // Declare and initialize 'i'
    FILE *fp, *fd;
      printf("Enter the File you want to modify\n");
    scanf("%s", input);

    fp = fopen(input, "r");
    if (fp == NULL) {
        printf("Unable to open the file. Please check the file name.\n");
        return 1;
    }

    while ((ch1 = fgetc(fp)) != EOF)
        c++;
    rewind(fp);

    p = (char *)malloc(sizeof(char) * (c + 1));
    while ((ch1 = fgetc(fp)) != EOF)
        p[j++] = ch1;
    p[j] = '\0';
    fclose(fp);

       char *temp[16];
	for(j=0;j<16;j++)
		temp[j] = (char*)malloc(sizeof(char) * (c + 1));

	printf("%s\n",p);
	printf("Do you want to write the content on new file?\nPress y or Y for Yes\n");
	scanf(" %c",&ch);
	if(ch == 'y' || ch == 'Y')
	{
		printf("Enter the new output file name\n");
		scanf("%s",output);
		do
		{
			printf("Option\n1>'.' Extra dots removal\n2>',' Extra comma's remomval\n3>' ' Extra space removal\n4>Uppercse the letter after '.'\n5>All four operation\n6>'.' and ',' removal\n7>'.' and ' ' removal\n8>'.' removal and uppercase\n9>',' and ' ' removal\n10>',' removal and uppercase\n11>' ' removal and uppercase\n12>'.' and ',' and ' ' removal\n13>'.' and ',' removal and uppercase\n14>'.' and ' ' removal and uppercse\n15>',' and ' ' removal and uppercase\n16>Middle 'i' to 'I'\n17>Undo\n18>Redo\n");
			printf("Enter your option for correction\n");
			scanf("%d",&op);
			switch(op)
			{
				case 1: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 2:
					strcpy(temp[i],p);
					i_max=i;
					comma_remov(p,',');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 3: 
					strcpy(temp[i],p);
					i_max=i;
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 4: 
					strcpy(temp[i],p);
					i_max=i;
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 5: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 6: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fd=fopen(output,"w");
					i++;
					fputs(p,fd);
					break;
				case 7: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fd=fopen(output,"w");
					i++;
					fputs(p,fd);
					break;
				case 8: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					uppercase(p,'s');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fd=fopen(output,"w");
					i++;
					fputs(p,fd);
					break;
				case 9: 
					strcpy(temp[i],p);
					i_max=i;
					comma_remov(p,',');
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fd=fopen(output,"w");
					i++;
					fputs(p,fd);
					break;
				case 10: 
					strcpy(temp[i],p);
					i_max=i;
					comma_remov(p,',');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 11: 
					strcpy(temp[i],p);
					i_max=i;
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fp=fopen(output,"w");
					i++;
					fputs(p,fp);
					break;
				case 12: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fd=fopen(output,"w");
					i++;
					fputs(p,fd);
					break;
				case 13: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 14: 
					strcpy(temp[i],p);
					i_max=i;
					dot_remov(p,'.');
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fd=fopen(output,"w");
					i++;
					fputs(p,fd);
					break;
				case 15: 
					strcpy(temp[i],p);
					i_max=i;
					comma_remov(p,',');
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					fd=fopen(output,"w");
					i++;
					fputs(p,fd);
					break;
				case 16: 
					strcpy(temp[i],p);
					i_max=i;
					i_I_conv(p);
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					printf("Previous file\n\n");
					printf("%s\n\n",temp[i]);
					i++;
					fd=fopen(output,"w");
					fputs(p,fd);
					break;
				case 17:
					if(i==0)
						printf("File Already in its Original form\n");
					else
					{
						strcpy(p,temp[i]);
						printf("Updated text\n\n");
						printf("%s\n\n",p);
						i--;
						fd=fopen(output,"w");
						fputs(p,fd);
					}
					break;
				case 18:
					if(i_max>i)
						printf("Redo reach its max didn't have any modified file\n");
					else
					{
						i++;
						strcpy(p,temp[i]);
						printf("Updated text\n\n");
						printf("%s\n\n",p);
						fd=fopen(output,"w");
						fputs(p,fd);
					}
					break;
				default: printf("Invalid Option Choosen\n");
			}
			printf("Do you want to continue the change, press y/y to continue\n");
			scanf(" %c",&ch2);
		}while(ch2 == 'y' || ch2 == 'Y');
	}
	else
	{
		do
		{
			printf("Option\n1>'.' Extra dots removal\n2>',' Extra comma's remomval\n3>' ' Extra space removal\n4>Uppercse the letter after '.'\n5>All four operation\n6>'.' and ',' removal\n7>'.' and ' ' removal\n8>'.' removal and uppercase\n9>',' and ' ' removal\n10>',' removal and uppercase\n11>' ' removal and uppercase\n12>'.' and ',' and ' ' removal\n13>'.' and ',' removal and uppercase\n14>'.' and ' ' removal and uppercse\n15>',' and ' ' removal and uppercase\n16>Middel 'i' to 'I'\n17>Undo\n18>Redo\n");
			printf("Enter your option for correction\n");
			scanf("%d",&op);
			switch(op)
			{
				case 1: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 2:
					strcpy(temp[i],p);
					i++;
					i_max=i;
					comma_remov(p,',');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 3: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 4: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 5: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 6: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 7: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 8: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					uppercase(p,'s');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 9: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					comma_remov(p,',');
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 10: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					comma_remov(p,',');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 11: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 12: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					space_remov(p,' ');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 13: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					comma_remov(p,',');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 14: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					dot_remov(p,'.');
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 15: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					comma_remov(p,',');
					space_remov(p,' ');
					uppercase(p,'.');
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 16: 
					strcpy(temp[i],p);
					i++;
					i_max=i;
					i_I_conv(p);
					printf("Updated text\n\n");
					printf("%s\n\n",p);
					fp=fopen(input,"w");
					fputs(p,fp);
					break;
				case 17:
					if(i==0)
						printf("File Already in its Original form\n");
					else
					{
						i--;
						strcpy(p,temp[i]);
						printf("Updated text\n\n");
						printf("%s\n\n",p);
						fd=fopen(input,"w");
						fputs(p,fd);
					}
					break;
				case 18:
					if(i_max>i)
						printf("Redo rech its max didn't have any modified file\n");
					else
					{
						i++;
						strcpy(p,temp[i]);
						printf("Updated text\n\n");
						printf("%s\n\n",p);
						fd=fopen(input,"w");
						fputs(p,fd);
					}
					break;
				default: printf("Invalid Option Choosen\n");
			}
			printf("Do you want to continue the change, press y/y to continue\n");
			scanf(" %c",&ch2);
		}while(ch2 == 'y' || ch2 == 'Y');
	}



    free(p); // Don't forget to free dynamically allocated memory
    return 0;
    
 
}
