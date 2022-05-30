// See https://aka.ms/new-console-template for more information

int row1, col1, row2, col2, i, j;

Console.Write("Enter Row-1 Number : ");
row1 = Convert.ToInt32(Console.ReadLine());

Console.Write("Enter Column-1 Number : ");
col1 = Convert.ToInt32(Console.ReadLine());


double[,] arr1 = new double[row1, col1];


Console.WriteLine("Insert a 2D matrix-1: ");

for (i = 0; i < row1; i++)
{
    for (j = 0; j < col1; j++)
    {
        Console.Write("insert  [{0},{1}] : ", i, j);
        arr1[i, j] = Convert.ToDouble(Console.ReadLine());
    }
}


Console.Write("Enter Row2 Number : ");
row2 = Convert.ToInt32(Console.ReadLine());

Console.Write("Enter Column-2 Number : ");
col2 = Convert.ToInt32(Console.ReadLine());
double[,] arr2 = new double[row2, col2];

Console.WriteLine("Insert a 2D matrix-2: ");

for (i = 0; i < row2; i++)
{
    for (j = 0; j < col2; j++)
    {
        Console.Write("insert  [{0},{1}] : ", i, j);
        arr2[i, j] = Convert.ToDouble(Console.ReadLine());
    }
}

Console.Write("Input matrix-1 is : \n");
for (i = 0; i < row1; i++)
{
    for (j = 0; j < col1; j++)
    {
        Console.Write("{0}\t", arr1[i, j]);
    }
    Console.WriteLine();
}

Console.Write("Input matrix-2 is : \n");
for (i = 0; i < row2; i++)
{
    for (j = 0; j < col2; j++)
    {
        Console.Write("{0}\t", arr2[i, j]);
    }
    Console.WriteLine();
}

if (col1 != row2)
{
    Console.WriteLine("Invalid Input (cannot be multiplied)");
    Console.Read();
}
else
{
    double[,] c = new double[row1, col2];
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            c[i, j] = 0;
            for (int k = 0; k < col1; k++)
            {
                c[i, j] += arr1[i, k] * arr2[k, j];
            }
        }
    }
    Console.WriteLine("The product of the two matrices is :");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            Console.Write(c[i, j] + "\t");
        }
        Console.WriteLine();
    }
    Console.Read();
}
