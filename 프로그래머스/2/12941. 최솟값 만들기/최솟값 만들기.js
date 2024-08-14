function solution(A,B){
    // 0. 두 배열을 각각 오름차순, 내림차순으로 정렬하여 순서대로 곱한 값이 최솟값이라고 판단
    let answer = 0;
    
    A.sort(function comp(a, b) {
        return a - b;
    });
    
    B.sort(function comp(a, b) {
        return b - a;
    });
    
    for (let i = 0; i < A.length; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}