//implemented  by denso -- 2020
//FUNCIONAMIENTO CORRECTO
int abs(int a, int b)
{
    int val = a - b;

    if (val < 0)
        return val * -1;
    return val;
}

//FUNCIONAMIENTO CORRECTO
int valid(int a[], int stage)
{
    for (int i(0); i < stage; i++)
        if (a[i] == a[stage] or (abs(i, stage) == abs(a[i], a[stage])))
            return false;

    return true;
}

bool Queens(int Solution[], int n, int stage)
{
    if (stage >= n)
        return true;

    bool success = false;
    Solution[stage] = -1;

    while (!success)
    {

        Solution[stage] += 1;

        if (stage < n and Solution[stage] < n)
        {
            if (valid(Solution, stage))
                success = Queens(Solution, n, stage + 1);
        }
        else
            break;
    }
    return success;
}