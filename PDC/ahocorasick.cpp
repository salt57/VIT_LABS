#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

const int MAXS = 500;
const int MAXC = 26;
int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];


int parallel_buildFSM(string arr[], int k)
{
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);
    int states = 1;

    #pragma omp parallel for
    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int curState = 0;

        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
            if (g[curState][ch] == -1)
                g[curState][ch] = states++;

            curState = g[curState][ch];
        }

        out[curState] |= (1 << i);
    }

    #pragma omp parallel for
    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;

    memset(f, -1, sizeof f);
    queue<int> q;

    #pragma omp parallel for
    for (int ch = 0; ch < MAXC; ++ch)
    {
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (q.size())
    {
        int state = q.front();
        q.pop();

        #pragma omp parallel for
        for (int ch = 0; ch <= MAXC; ++ch)
        {
            if (g[state][ch] != -1)
            {
                int failure = f[state];

                while (g[failure][ch] == -1)
                    failure = f[failure];

                failure = g[failure][ch];
                f[g[state][ch]] = failure;

                out[g[state][ch]] |= out[failure];
                q.push(g[state][ch]);
            }
        }
    }

    return states;
}
int serial_buildFSM(string arr[], int k)
{
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);
    int states = 1;

    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int curState = 0;

        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
            if (g[curState][ch] == -1)
                g[curState][ch] = states++;

            curState = g[curState][ch];
        }

        out[curState] |= (1 << i);
    }

    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;

    memset(f, -1, sizeof f);
    queue<int> q;

    for (int ch = 0; ch < MAXC; ++ch)
    {
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (q.size())
    {
        int state = q.front();
        q.pop();

        for (int ch = 0; ch <= MAXC; ++ch)
        {
            if (g[state][ch] != -1)
            {
                int failure = f[state];

                while (g[failure][ch] == -1)
                    failure = f[failure];

                failure = g[failure][ch];
                f[g[state][ch]] = failure;

                out[g[state][ch]] |= out[failure];
                q.push(g[state][ch]);
            }
        }
    }

    return states;
}


int findNext(int curState, char nextInput)
{
    int answer = curState;
    int ch = nextInput - 'a';

    while (g[answer][ch] == -1)
        answer = f[answer];

    return g[answer][ch];
}


void aho_search(string arr[], int k, string text, int config)
{
    if(config == 0)
        serial_buildFSM(arr, k);
    else
        parallel_buildFSM(arr, k);
    int curState = 0;

    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i] == ' '){
            continue;
        }

        curState = findNext(curState, text[i]);

        if (out[curState] == 0)
            continue;

        for (int j = 0; j < k; ++j)
        {
            if (out[curState] & (1 << j))
            {
                cout << "Word " << arr[j] << " appears from "
                     << i - arr[j].size() + 1 << " to " << i << endl;
            }
        }
    }
}

int main()
{
    cout << "Sourish Gupta - 20BCE0453" << endl;
    string arr[] = {"lore", "tute", "tech"};
    string text = "vellore institute of technology";
    int k = sizeof(arr) / sizeof(arr[0]);

    int config = 0;
    double st = omp_get_wtime();
    aho_search(arr, k, text, config);
    cout << "serial time: " << 1000*(omp_get_wtime() - st) << "ms" << endl;

    config = 1;
    double pt = omp_get_wtime();
    aho_search(arr, k, text, config);
    cout << "parallel time: " << 1000*(omp_get_wtime() - pt) << "ms" << endl;

    return 0;
}