int count(int N,vector<vector<int>> A,vector<vector<int>> B) {
      int posNotEqual = 0;
      vector<int> cntA(2, 0), cntB(2, 0);
      for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
              if(A[i][j] != B[i][j]) posNotEqual += 1;
              cntA[A[i][j]] += 1;
              cntB[A[i][j]] += 1;
          }
      }

      if(cntA[0] != cntB[0] or cntA[1] != cntB[1] or (posNotEqual & 1)) return -1;

      return posNotEqual / 2;
}