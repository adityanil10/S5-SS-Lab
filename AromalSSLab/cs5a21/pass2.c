#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void passOne(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3]);
void display();

int main()
{
    // for reading from input
    char label[10], opcode[10], operand[10];
    // for reading from optab
    char code[10], mnemonic[3];
    // call the function
    passTwo(label, opcode, operand, code, mnemonic);

    return 0;
}

void passTwo(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3]) 
{
    int locctr, start, length, i;

    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7;                                    // file pointers

    // read mode
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "r");
    fp4 = fopen("intermediate.txt", "r");
    fp5 = fopen("length.txt", "r");
    
    // write mode
    fp6 = fopen("assembly_listing.txt", "w");
    fp7 = fopen("object_program.txt", "w");

    fscanf(fp4, "%s\t%s\t%s\t%s\n", locctr, label, opcode, operand);              // read first line

    if (strcmp(opcode, "START") == 0) {                       
        // atoi() requires stdlib.h header file
        start = atoi(operand);                                      // convert operand value from string to integer and assign to start
        fscanf(fp5,"%d",&length);
    } 
    
    printf("H^%s^%s^%d\nT^00%s^",label,start,length,start);
	fscanf(fp4, "%s\t%s\t%s\t%s\n", locctr, label, opcode, operand);
	
	// iterate till end
    while (strcmp(opcode, "END") != 0)
	{
	//fscanf(fp2,"%s%s",code,op);
	fscanf(fp2, "%s\t%s", code, mnemonic);
	while(!feof(fp2))
	{
		if(strcmp(opcode,code)==0)
		{
			fclose(fp2);
			fscanf(fp3, "%s\t%d\n", label, locctr);
			while(!feof(fp3))
			{
				if(strcmp(operand,label)==0)
				{
					printf("%s%s^",mnemonic,locctr);
					break;
				}
				else
					fscanf(fp3, "%s\t%d\n", label, locctr);
			}
			break;
		}
		else
			fscanf(fp2,"%s%s",code,mnemonic);
		}
		if((strcmp(opcode,"BYTE")==0)||(strcmp(opcode,"WORD")==0))
		{
			if(strcmp(opcode,"WORD")==0)
			printf("0000%s^",operand);
			else
			{
				length=strlen(operand);
				for(i=2;i<length;i++)
				{
					printf("%d",operand[i]);
				}
				printf("^");
			}
		}
		fscanf(fp4, "%s\t%s\t%s\t%s\n", locctr, label, opcode, operand);
		fp2=fopen("optab.txt","r");
		fseek(fp2,SEEK_SET,0);
	}
	printf("\nE^00%s\n",start);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	fclose(fp6);
	fclose(fp7);
	/*	
    
    else {
        locctr = 0;
    }

    // iterate till end
    while (strcmp(opcode, "END") != 0) {

        // 1. transfer address and read line to output file
        fprintf(fp4, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        // 2. make symtab file with values not starting with **
        if (strcmp(label, "**") != 0) {
            fprintf(fp3, "%s\t%d\n", label, locctr);
        }

        // 3. read from optab (code and mnemonic value)
        fscanf(fp2, "%s\t%s", code, mnemonic);

        // 4. traverse till the end of optab file
        while (strcmp(code, "END") != 0) {
            if (strcmp(opcode, code) == 0) {                        // if opcode in input matches the one in optab, increment locctr by 3
                locctr += 3;
                break;
            }
            // read next line
            fscanf(fp2, "%s\t%s", code, mnemonic);
        }

        // 5. Searching opcode for WORD, RESW, BYTE, RESB keywords and updating locctr
        
                // WORD -> add 3 to locctr
        if (strcmp(opcode, "WORD") == 0) {
            locctr += 3;
        }
                // RESW -> add 3*operand to locctr
        else if (strcmp(opcode, "RESW") == 0) {
            locctr += (3 * (atoi(operand)));                        // convert operand to integer and multiply with 3
        }
                // BYTE -> add 1 to locctr 
        else if (strcmp(opcode, "BYTE") == 0) {
            ++locctr;
        }
                // RESB -> add operand to locctr
        else if (strcmp(opcode, "RESB") == 0) {
            locctr += atoi(operand);
        }
        
        // read next line
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    // 6. transfer last line to file
    fprintf(fp4, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    // 7. Close all files
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);

    // 8. display outputs
    display();
    
    // 9. calculate length of program
    length = locctr - start;
    fprintf(fp5, "%d", length);
    fclose(fp5);
    printf("\nThe length of the code : %d\n", length);
    */
}

void display() {

    char str;
    FILE *fp1, *fp2, *fp3;   

    // 1. Input Table
    printf("\nThe contents of Input Table :\n\n");
    fp1 = fopen("int.txt", "r");
    str = fgetc(fp1);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp1);
    }
    fclose(fp1);

    //2. Output Table
    printf("\n\nThe contents of Output Table :\n\n");
    fp2 = fopen("intermediate.txt", "r");
    str = fgetc(fp2);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp2);
    }
    fclose(fp2);

    // 3. Symtable
    printf("\n\nThe contents of Symbol Table :\n\n");
    fp3 = fopen("symtab.txt", "r");
    str = fgetc(fp3);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp3);
    }
    fclose(fp3);
}

/*
input.txt
---------
**	START	2000
**	LDA	FIVE
**	STA	ALPHA
** 	LDCH 	CHARZ
** 	STCH 	C1
ALPHA 	RESW 	2
FIVE 	WORD 	5
CHARZ 	BYTE 	C'Z'
C1 	RESB 	1
** 	END	**
optab.txt
---------
LDA 03
STA	0f
LDCH	53
STCH	57
END	*
-----------------------------
symtab.txt
----------
ALPHA   2012
FIVE    2018
CHARZ   2021
C1      2022
intermediate.txt
----------------
        **      START   2000
2000    **      LDA     FIVE
2003    **      STA     ALPHA
2006    **      LDCH    CHARZ
2009    **      STCH    C1
2012    ALPHA   RESW    2
2018    FIVE    WORD    5
2021    CHARZ   BYTE    C'Z'
2022    C1      RESB    1
2023    **      END     **
length.txt
----------
23
*/
