using System;

namespace BenchMarkCS
{
    class Program
    {
        static void Main(string[] args)
        {
            int maxSize = 350;
            for (int size = 50; size <= maxSize; size += 50)
            {
                MatrixMultiplication(size);
            }

            Console.ReadKey();
        }
        
        public static void MatrixMultiplication(int length)
        {
            int[][] matrix = new int[length][];
            int[][] resultantMatrix = new int[length][];

            CreateMatrix(length, matrix, resultantMatrix);
            PopulateMatrix(length, matrix);

            DateTime start = DateTime.Now;
            for (int i = 0; i < length; i++)
                for (int j = 0; j < length; j++)
                    for (int k = 0; k < length; k++)
                        resultantMatrix[i][j] += matrix[i][k] * matrix[k][j];

            Console.WriteLine($"Time for matrix of int of size {length}: {(DateTime.Now - start).TotalMilliseconds} ms");
        }

        private static void PopulateMatrix(int length, int[][] matrix)
        {
            Random random = new Random();
            for (int i = 0; i < length; i++)
                for (int j = 0; j < length; j++)
                    matrix[i][j] = random.Next(0, 9);
        }

        private static void CreateMatrix(int length, int[][] matrix, int[][] resultantMatrix)
        {
            for (int i = 0; i < length; i++)
            {
                matrix[i] = new int[length];
                resultantMatrix[i] = new int[length];
            }
        }
    }
}