function solution(skill, skill_trees) {
    let answer = 0;
    
    for (const str of skill_trees) {
        let flag = -1;
        for (let i = skill.length - 1; i >= 0; i--) {
            const cur = skill[i];
            
            if (flag === -1) {
                if (str.indexOf(cur) !== -1) {
                    flag = str.indexOf(cur);
                }
            } else {
                if (str.indexOf(cur) === -1) {
                    flag = -2;
                    break;
                } else if (str.indexOf(cur) < flag) {
                    flag = str.indexOf(cur);
                } else {
                    flag = -2;
                    break;
                }
            }
        }
        
        if (flag !== -2) {
            answer++;
        }
    }
    
    return answer;
}