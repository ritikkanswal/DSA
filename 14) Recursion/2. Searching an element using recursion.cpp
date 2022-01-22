

int search(int arr[], int N, int X)
{

    if (N == 0)
        return -1;
    if (arr[N - 1] == X)
        return N - 1;
    return search(arr, N - 1, X);
}