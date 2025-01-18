// 43_minimum_platforms.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Sort arrivals and departures separately.
  Sweep line: use two pointers to count overlaps.
*/

int findPlatform(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i=0, j=0, plat_needed=0, maxPlat=0;
    while (i < arr.size() && j < dep.size()) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            maxPlat = max(maxPlat, plat_needed);
            i++;
        } else {
            plat_needed--;
            j++;
        }
    }
    return maxPlat;
}

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum platforms required: " << findPlatform(arr, dep) << '\n';
    return 0;
}
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}   int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}   int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}                               int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}   int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}   int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}   int n = 8;
    vector<vector<string>> solutions;       
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);  
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}   int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);