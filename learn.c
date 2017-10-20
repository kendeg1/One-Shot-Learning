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
	
	
        double **m1 = malloc(rows*sizeof(double *));
        for(i = 0; i < rows; i++){
            m1[i]=malloc(columns*sizeof(double));
            for( j = 0; j<columns; j++){
                fscanf(filepointer,"%lf, \n",&m1[i][j]);
            }
        }
        for(i = 0; i<rows;i++){
            for(j=0;j<columns;j++){
                printf("%lf\t",m1[i][j]);
            }
            printf("\t\n");
        }
        printf("\ntranspose test");
        
        
     double **m1t = malloc(columns*sizeof(double *));
      for(i = 0; i<columns;i++){
        m1t[i]=malloc(rows*sizeof(double));
        for(j=0;j<rows;j++){
        fscanf(filepointer,"%lf, \n",&m1t[j][i]); 
               }
    }
    for(i = 0; i<columns;i++){
        for(j=0; j<rows; j++){
        printf("%lf\t",m1t[j][i]);
        }
        printf("\t\n");
    }
    
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
    //transposeMatrix(m2,rows,attribute);
   
   printf("\n");
   double **m2t = malloc(attribute*sizeof(double *));
    for(i = 0; i<attribute;i++){
        m2t[i]=malloc(rows*sizeof(double));
        for(j=0;j<rows;j++){
        fscanf(filepointer,"%lf, \n",&m2t[j][i]); 
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
