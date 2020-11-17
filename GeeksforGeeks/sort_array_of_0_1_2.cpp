
int main()
{

    //code
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s = 0, j = 0;
        scanf("%d", &s); //cin>>s;
        int a[s];
        int b[s];
        for (int i = 0; i < s; i++)
            scanf("%d", &a[i]); //cin>>a[i];
        for (int i = 0; i < s; i++)
        {
            if (a[i] == 0)
            {
                b[j] = a[i];
                j++;
            }
        }
        for (int i = 0; i < s; i++)
        {
            if (a[i] == 1)
            {
                b[j] = a[i];
                j++;
            }
        }
        for (int i = 0; i < s; i++)
        {
            if (a[i] == 2)
            {
                b[j] = a[i];
                j++;
            }
        }
        for (int i = 0; i < s; i++)
        {
            printf("%d", b[i]);
            printf("%s", " ");
        } //cout<<b;
        printf("%s", "\n");
    }
    return 0;
}