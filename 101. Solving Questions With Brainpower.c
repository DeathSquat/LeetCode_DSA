long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    // Create DP array, size + 1 to handle beyond-end case
    long long* dp = (long long*)calloc(questionsSize + 1, sizeof(long long));
    if (!dp) return 0; // Memory allocation check
    
    // Iterate from last question to first
    for (int i = questionsSize - 1; i >= 0; i--) {
        int points_i = questions[i][0];      // points for question i
        int brainpower_i = questions[i][1];  // questions to skip if solved
        int next_idx = i + brainpower_i + 1; // Next solvable question
        
        // Option 1: Skip current question
        long long skip = dp[i + 1];
        
        // Option 2: Solve current question
        long long solve = points_i;
        if (next_idx <= questionsSize) {
            solve += dp[next_idx];
        }
        
        // Take maximum of solve or skip
        dp[i] = (solve > skip) ? solve : skip;
    }
    
    // Store result and free memory
    long long result = dp[0];
    free(dp);
    return result;
}
