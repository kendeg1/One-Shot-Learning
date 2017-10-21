#include <stdio.h>
#include <stdlib.h>


/*invert
transpose
multiplication*/

/*double **transposeMatrix(double** matrix, int rows, int columns){
    int rc, cc, i, j;
    double **mtx;
    for(i = 0;i<rows;i++){
    rc++;
        for(j = 0; j<columns; j++){
        cc++;
        }
    }
    mtx = malloc(cc*sizeof(double *));
    for(i = 0; i<cc; i++){
        mtx[i]=malloc(rc*sizeof(double));
        for(j = 0; j<rc;j++){
        mtx[i][j]=matrix[j][i];
        }
    }
    for(i=0; i<cc;i++){
        for(j=0;j<rc;j++){
        printf("%lf\t",mtx[j][i]);
        }
        printf("\t\n");
    }
    return mtx;
}
*/
void printMatrix(double **matrix, int r, int c ){
    int i,j;
     for(i = 0; i<r;i++){
        for(j=0; j<c; j++){
        printf("%lf ",matrix[i][j]);
        }
        printf("\t\n");
    }   
}

double **multiplyMatrix(double **m1, int r1, int c1, double **m2, int r2, int c2){
    int i,j,k;
    double total = 0;
 
    double **result = malloc(r1*sizeof(double*));
    for(i = 0; i < r1; i++){
        result[i] = malloc(c2*sizeof(double));
    }
    
    for(i=0;i<r1;i++){
        for(j = 0; j<c2;j++){
            for(k=0;k<r2;k++){
            total = total + m1[i][k] * m2[k][j];
            }
            result[i][j]=total;
            total = 0;
        }
    }
    return result;
}

int main(int argc, char** argv){
    
    int rows,columns;
    int i,j;
    int attribute;
    
    if(argc!=3){
      return 0;
    }
    
    //this is train matrix
    FILE *filepointer = fopen(argv[1], "r");
    if (filepointer == NULL){
      printf("error\n");
      return 0;
    }
    fscanf(filepointer,"%d\n",&attribute);
	//printf("%d number of attributes\n",attribute);

	columns = attribute + 1;

	//printf("%d number of columns\n",columns);
	fscanf(filepointer,"%d\n",&rows);
	//printf("%d number of rows\n",rows);
   
   //printf("\nThis is the original Train Matrix\n");
   double **m1 = malloc(rows*sizeof(double *));
    for(i = 0; i<rows;i++){
        m1[i]=malloc(columns*sizeof(double));
        for(j=0;j<columns;j++){
          fscanf(filepointer,"%lf, \n",&m1[i][j]); 
          }      
    }
   // printMatrix(m1,rows,columns);   
    
   // printf("rows = %d\n",columns);
	//printf("columns = %d\n",rows);
    //printf("This is TRANSPOSE of ORIGINAL TRAIN MATRIX\n");
   double **m1t = malloc(columns*sizeof(double *));
    for(i = 0; i<columns;i++){
        m1t[i]=malloc(rows*sizeof(double));
        for(j=0;j<rows;j++){
        m1t[i][j] = m1[j][i];
               }
    }
    
  // printMatrix(m1t,columns,rows);
    
    //printf("\nThis is Train Matrix with first column of 1s\n");
   
   double **mX = malloc(rows*sizeof(double *));
    for(i=0; i <rows;i++){
        mX[i]=malloc(columns*sizeof(double));
        for(j=0;j<columns;j++){
        if(j == 0){
            mX[i][0] = 1;
        }else{
         mX[i][j] = m1[i][j-1];
        }
        }
    }
    //printMatrix(mX,rows,columns);
 
    //printf("\nThis is TRANSPOSE of COLUMNS OF 1 TRAIN MATRIX\n");
    double **mXt = malloc(columns*sizeof(double *));
    for(i=0; i <columns;i++){
        mXt[i]=malloc(rows*sizeof(double));
        for(j=0;j<rows;j++){
         mXt[i][j] = mX[j][i];
        }
        }

    //printMatrix(mXt,columns,rows);
    //printf("This is XT * X\n");
    double **result = multiplyMatrix(mXt,columns, rows, mX, rows, columns);
    printf("\n");
    printMatrix(result, columns, columns);

    int m=0;
    int n=0;
    int k = 1;
    double num;
    
    
        if(result[m][n]!=1){
        num = result[m][n];
            for(n = 0; n<columns;n++){
                result[m][n] = result[m][n]/num;
                printf("m = %d n = %d num = %lf\n",m,n,num);
                 for(k=0;k<columns;k++){
                    if(result[k][n]!=0){
                    printf("k = %d\n",k);
                    
                    
            }
                }
            
           }     
                
    }
    printf("\n\n");
    printMatrix(result,columns,columns);
    

    
       /* for(z=0;z<columns;z++){
        result[count][z] = result[count][z]/num; 
        printf("\n      num =          %lf    \n\n",num);
         
            for(k=(z+1);k<columns;k++){
            if(result[k][z]!=0){
            num = result[k][z];
            result[k][z] = result[k][z] - result[count][z] * num;
            
             }
          }
        }
        count++;
        }
    
    */
    //printf("\n");
   // printMatrix(result,columns,columns);
	 
     
    //this is the test matrix
    filepointer = fopen(argv[2], "r");
    int testrow;
    if (filepointer == NULL){
      printf("error\n");
      return 0;
    }
    fscanf(filepointer,"%d\n",&testrow);
  //  printf("\n number of rows = %d\n",testrow);
    
   // printf("\nThis is original TEST MATRIX\n");
    double **m2 = malloc(testrow*sizeof(double *));
    for(i = 0; i<testrow;i++){
        m2[i]=malloc(attribute*sizeof(double));
        for(j=0;j<attribute;j++){
        fscanf(filepointer,"%lf, \n",&m2[i][j]); 
               }
    }
  //  printMatrix(m2,testrow,attribute);
   
   printf("\n");
   double **m2t = malloc(attribute*sizeof(double *));
    for(i = 0; i<attribute;i++){
        m2t[i]=malloc(testrow*sizeof(double));
        for(j=0;j<testrow;j++){
        m2t[i][j] = m2[j][i]; 
               }
    }
  //  printMatrix(m2t, attribute, testrow);
    
   // printf("\ntranspose\n");
    //transpose test
    



   

    return 0;
}
