#include<stdio.h>
#include<math.h>

double mat[105][105], a[105];

void polynomialRegression(int n);
void gaussJordan(int n);
void table (double a[]);
double* XY(double x[], double y[],int power, int n);
double correlation(double x[], double y[], int n);
double summation(double arr[], int power, int n);

int main(){

    double x[105], f[105];
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of X: ");

    for(int i = 0; i < n; i++){

        scanf("%lf", &x[i]);
    }

    printf("\n");

    printf("Enter the values of f(x): ");

    for(int i = 0; i < n; i++){

        scanf("%lf", &f[i]);
    }

    printf("\n");

    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 5; j++){

            if(i == 0 && j == 0){

                mat[i][j] = n;
            }

            else if (j != 4){

                mat[i][j] = summation(x, i+j, n);

            } else if(j == 4){

                mat[i][j] = summation(XY(x, f, i, n), 1, n);
            }
        }
    }

    gaussJordan(4);
    polynomialRegression(5);

    if(correlation(x, f, n) > 0){

        printf("\nStrong positive relation.\n");

    }

    else if(correlation(x, f, n) < 0){

        printf("\nStrong negative relation.\n");
    }

    else{

        printf("\nNo relation at all.\n");
    }

    table(a);

    return 0;
}

double summation(double arr[], int power, int n){

    double result = 0, res[105];

    for(int i = 0; i < n; i++){

        res[i] = pow(arr[i], power);
    }

    for(int i = 0; i < n; i++){

        result += res[i];
    }

    return result;
}

double* XY(double x[], double y[],int power, int n){

   static double xy[105], powX[105];

   for(int i = 0; i < n; i++){

        powX[i] = pow(x[i], power);
    }

    for(int i = 0; i < n; i++){

        xy[i] = powX[i] * y[i];
    }

    return xy;
}

void polynomialRegression(int n){

    printf("\nThe required equation is : ");

    for(int i = 0; i < n - 1; i++){

        if(i == 0){

            printf("%0.4lf ", a[i]);
        }

        else{

            if(a[i] < 0){

                printf("- %0.4lf X ^ %d ", fabs(a[i]), i);
            }

            else{

                printf("+ %0.4lf X ^ %d ", a[i], i);
            }

        }
    }

    printf("\n");

}

void gaussJordan(int n){

    int r = 0;
    double norm = 0, x = 0;

    for(int i = 0; i < n; i++){

            for(int j = 0; j <= n; j++){

                printf("%lf\t",mat[i][j]);
            }

            printf("\n");
        }

        printf("\n");

    while(r < n){

        norm = 1/mat[r][r];

        //normalize
        for(int i = 0; i <= n; i++){

            mat[r][i] = mat[r][i] * norm;

        }

        //removing x
        for(int i = 0; i < n; i++){

            x = mat[i][r];

            for(int j = 0; j <= n; j++){

                if(i != r){

                    mat[i][j] -= (x*mat[r][j]);
                }

                else{

                    break;
                }
            }
        }

        for(int i = 0; i < n; i++){

            for(int j = 0; j <= n; j++){

                printf("%lf\t",mat[i][j]);
            }

            printf("\n");
        }

        printf("\n");
        r++;
    }

    //roots
    for(int i = 0; i < n; i++){

        a[i] = mat[i][n]/mat[i][i];
    }
}

double correlation(double x[], double y[], int n){

    double R;

    R = ((n * summation(XY(x, y, 1, n), 1, n)) - (summation(x, 1, n) * summation(y, 1, n))) / (sqrt(((n * summation(x, 2, n)) - pow(summation(x, 1, n), 2)) * ((n * summation(y, 2, n)) - pow(summation(y, 1, n), 2))));

    return R;
}

void table (double a[]){

    printf("\nTemp\tSalinity\n");

    for(double x = 5; x <= 6; x+=0.01){

        printf("%0.2lf\t%lf\n", x,(a[0] + (a[1] * x) + (a[2] * pow(x, 2)) + (a[3] * pow(x, 3))));
    }
}

/*
23

5.88 34.131
5.87 34.078
7.44 34.223
7.24 34.219
6.68 34.229
6.89 34.263
6.57 34.208
6.24 34.145
6.04 34.123
5.96 34.089
7.39 34.264
7.50 34.261
7.26 34.271
6.93 34.214
6.64 34.194
6.72 34.237
6.91 34.223
6.68 34.278
6.15 34.138
6.29 34.094
7.29 34.241
7.19 34.224
7.39 34.268


5.88
5.87
7.44
7.24
6.68
6.89
6.57
6.24
6.04
5.96
7.39
7.50
7.26
6.93
6.64
6.72
6.91
6.68
6.15
6.29
7.29
7.19
7.39


34.131
34.078
34.223
34.219
34.229
34.263
34.208
34.145
34.123
34.089
34.264
34.261
34.271
34.214
34.194
34.237
34.223
34.278
34.138
34.094
34.241
34.224
34.268

*/

