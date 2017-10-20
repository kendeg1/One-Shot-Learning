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
	printf("%d number of attributes\n",attribute);

	columns = attribute + 1;

	printf("%d number of columns\n",columns);
	fscanf(filepointer,"%d\n",&rows);
	printf("%d number of rows\n",rows);
   
   printf("\nThis is the original Train Matrix\n");
   double **m1 = malloc(rows*sizeof(double *));
    for(i = 0; i<rows;i++){
        m1[i]=malloc(columns*sizeof(double));
        for(j=0;j<columns;j++){
          fscanf(filepointer,"%lf, \n",&m1[i][j]); 
          }      
    }
   for(i = 0; i<rows;i++){
        for(j=0; j<columns; j++){
        printf("%lf\t",m1[i][j]);
        }
        printf("\t\n");
    }   
    
    printf("rows = %d\n",columns);
	printf("columns = %d\n",rows);
    printf("This is TRANSPOSE of ORIGINAL TRAIN MATRIX\n");
   double **m1t = malloc(columns*sizeof(double *));
    for(i = 0; i<columns;i++){
        m1t[i]=malloc(rows*sizeof(double));
        for(j=0;j<rows;j++){
        m1t[i][j] = m1[j][i];
               }
    }
    
    for(i = 0; i<columns;i++){
        for(j=0; j<rows; j++){
        printf("%lf\t",m1t[i][j]);
        }
        printf("\t\n");
    }   
    
    
    printf("\nThis is Train Matrix with first column of 1s\n");
   
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
    for(i = 0; i<rows;i++){
        for(j=0; j<columns; j++){
        printf("%lf\t",mX[i][j]);
        }
        printf("\t\n");
    }   
    
 
    printf("\nThis is TRANSPOSE of COLUMNS OF 1 TRAIN MATRIX\n");
    double **mXt = malloc(columns*sizeof(double *));
    for(i=0; i <columns;i++){
        mXt[i]=malloc(rows*sizeof(double));
        for(j=0;j<rows;j++){
         mXt[i][j] = mX[j][i];
        }
        }
  
    
    for(i = 0; i<columns;i++){
        for(j=0; j<rows; j++){
        printf("%lf\t",mXt[i][j]);
        }
        printf("\t\n");
    }   
    
    printf("\nThis is original TEST MATRIX\n");
     
     
    //this is the test matrix
    filepointer = fopen(argv[2], "r");
    if (filepointer == NULL){
      printf("error\n");
      return 0;
    }
    fscanf(filepointer,"%d\n",&rows);
    printf("%d number of rows\n",rows);
    
    
    double **m2 = malloc(rows*sizeof(double *));
    for(i = 0; i<rows;i++){
        m2[i]=malloc(attribute*sizeof(double));
        for(j=0;j<attribute;j++){
        fscanf(filepointer,"%lf, \n",&m2[i][j]); 
               }
    }
    for(i = 0; i<rows;i++){
        for(j=0; j<attribute; j++){
        printf("%lf\t",m2[i][j]);
        }
        printf("\t\n");
    }
   
   printf("\n");
   double **m2t = malloc(attribute*sizeof(double *));
    for(i = 0; i<attribute;i++){
        m2t[i]=malloc(rows*sizeof(double));
        for(j=0;j<rows;j++){
        m2t[i][j] = m2[j][i]; 
               }
    }
    
    for(i = 0; i<attribute;i++){
        for(j=0; j<rows; j++){
        printf("%lf\t",m2[j][i]);
        }
        printf("\t\n");
    }
    
    
    printf("\ntranspose\n");
    //transpose test
    

    return 0;
}
