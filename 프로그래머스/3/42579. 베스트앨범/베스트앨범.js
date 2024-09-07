function solution(genres, plays) {
    let songs = genres.map((genre, idx) => {
        return {
            id : idx,
            genre: genre,
            play: plays[idx],
        };
    });
    
    const genrePlayCountMap = new Map();
    songs.forEach((song) => {
        if (genrePlayCountMap.get(song.genre)) {
            genrePlayCountMap.set(song.genre, genrePlayCountMap.get(song.genre) + song.play);
        } else {
            genrePlayCountMap.set(song.genre, song.play);
        }
    });
    
    songs.sort((a, b) => {
        if (genrePlayCountMap.get(b.genre) !== genrePlayCountMap.get(a.genre)) {
            return genrePlayCountMap.get(b.genre) - genrePlayCountMap.get(a.genre);
        } else {
            return b.play - a.play;
        }
    });
    
    console.log(songs);
    
    const genreFilterCount = new Map();
    
    const answer = songs.filter((song) => {
        if (genreFilterCount.get(song.genre) >= 2) 
            return false;
        else if (!genreFilterCount.get(song.genre)) {
            genreFilterCount.set(song.genre, 1);
            return true;
        } else {
            genreFilterCount.set(song.genre, genreFilterCount.get(song.genre) + 1);
            return true;
        }
    }).map((song) => song.id);

    return answer;
}