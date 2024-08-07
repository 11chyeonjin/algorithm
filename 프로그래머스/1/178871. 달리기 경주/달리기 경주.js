function solution(players, callings) {
    let playerMap = new Map();
    
    players.forEach((player, index) => {
        playerMap.set(player, index);
    })
    
    for (const callPlayer of callings) {
        let curIdx = playerMap.get(callPlayer);
        let tmpPlayer = players[curIdx - 1];
        playerMap.set(callPlayer, curIdx - 1);
        playerMap.set(tmpPlayer, curIdx);
        [players[curIdx], players[curIdx -1]] = [players[curIdx -1], players[curIdx]];
    }
    
    return players;
}