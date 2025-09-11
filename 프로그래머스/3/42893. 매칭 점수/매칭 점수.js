function isAlpha(str) {
    if (str.length === 1) {
        if ("a" <= str[0] && str[0] <= "z") {
            return true;
        }
    }
    
    if ("a" <= str[1] && str[1] <= "z") {
        if ("\\" === str[0]) {
            return false;
        }

        return true;
    }

    return false;
}

function solution(word, pages) {
    word = word.toLowerCase();
    const word_size = word.length;
    // word = 검색어 문자열
    // pages = html 문자열이 요소인 배열
    
    // 기본점수 = 텍스트 중, 검색어가 등장하는 횟수(대소문자 무시)
    // 외부 링크 수 = 외부 링크의 개수
    // 링크 점수 = 타겟 페이지 링크가 있는 다른 웹 페이지의 (기본점수 / 외부 링크 수)의 총합
    // 매칭점수 = 기본점수 + 링크점수
    
    pages = pages.map(page => {
        return page.toLowerCase();
    });
    
    const urlArr = [];
    const wordCntArr = Array.from({ length: pages.length }, () => 0);
    const exLinkArr = Array.from({ length: pages.length }, () => []);
    const linkMap = new Map();
    
    for (let i = 0; i < pages.length; i++) {
        const page = pages[i];
        
        // 고유 url
        const url_format = "<meta property=\"og:url\" content=";
        const url_start = page.indexOf(url_format);
        const url_end = page.indexOf("\"", url_start + url_format.length + 1);
        const url = page.slice(url_start + url_format.length + 1, url_end);
        urlArr.push(url);
        
        // 검색어
        let wfi = 0;
        while(wfi < page.length) {
            let search_rst = page.indexOf(word, wfi);
            
            if (search_rst === -1) {
                break;
            }
            
            if (search_rst > 0 && !isAlpha(page.slice(search_rst - 2, search_rst))) {
                if (search_rst + word_size < page.length && !isAlpha(page[search_rst + word_size])) {
                    wordCntArr[i]++;
                }
            }
            
            wfi = search_rst + word_size + 1;
        }
        
        // 외부 링크
        let lfi = 0;
        while(lfi < page.length) {
            const link_format = "<a href=\"";
            let search_rst = page.indexOf(link_format, lfi);
            
            if (search_rst === -1) {
                break;
            }
            
            const link_end = page.indexOf("\"", search_rst + link_format.length + 1);
            
            exLinkArr[i].push(page.slice(search_rst + link_format.length, link_end));
            
            // 변경
            lfi = link_end;
        }
    }
    
    urlArr.forEach((e, i) => {
        linkMap.set(e, i);
    })
    
    const intoLinkSetArr = Array.from({ length: pages.length }, () => new Set());
    
    exLinkArr.forEach((exLink, i) => {
        exLink.forEach((link) => {
            if (linkMap.has(link)) {
                intoLinkSetArr[linkMap.get(link)].add(i);
            }
        })
    })
    
    const scoreArr = Array.from({ length: pages.length }, () => 0);
    const linkScoreArr = Array.from({ length: pages.length }, () => 0);
    
    for (let i = 0; i < pages.length; i++) {
        linkScoreArr[i] = wordCntArr[i] / exLinkArr[i].length;
    }
    
    for (let i = 0; i < pages.length; i++) {
        scoreArr[i] += wordCntArr[i];
        
        intoLinkSetArr[i].forEach(e => {
            scoreArr[i] += linkScoreArr[e];
        })
    }

    return scoreArr.indexOf(Math.max(...scoreArr));
}