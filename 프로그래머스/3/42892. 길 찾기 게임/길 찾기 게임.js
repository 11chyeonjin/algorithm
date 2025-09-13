function solution(nodeinfo) {
    // 이전 문제 25분 소요
    
    // 그래프 전체를 클래스로 만들기
    // 노드를 클래스로 만들기
    
    class Node {
        constructor([x, y, i]) {
            this.i = i;
            this.x = x;
            this.y = y;
            this.left = null;
            this.right = null;
        }
        
        push([x, y, i]) {
            if (x > this.x) {
                if (this.right === null) {
                    this.right = new Node([x, y, i]);
                } else {
                    this.right.push([x, y, i]);
                }
            } else {
                if (this.left === null) {
                    this.left = new Node([x, y, i]);
                } else {
                    this.left.push([x, y, i]);
                }
            }
        }
    }

    const nodeArr = [];
    
    nodeinfo.forEach(([x, y], i) => {
        nodeArr.push([x, y, i + 1]);
    })
    
    nodeArr.sort((a, b) => {
        const [a_x, a_y] = a;
        const [b_x, b_y] = b;
        
        if (a_y < b_y) {
            return 1;
        } else if (a_y === b_y) {
            if (a_x < b_x) {
                return -1;
            } else {
                return 1;
            }
        } else {
            return -1;
        }
    });
    
    const node = new Node(nodeArr[0]);
    
    for (let i = 1; i < nodeArr.length; i++) {
        node.push(nodeArr[i]);
    }
    
    const preAnswer = [];
    const postAnswer = [];
    
    function preorder(node) {
        if (node === null) {
            return;
        }
        
        preAnswer.push(node.i);
        preorder(node.left);
        preorder(node.right);
    }
    
    preorder(node);
    
    function postorder(node) {
        if (node === null) {
            return;
        }
        
        postorder(node.left);
        postorder(node.right);
        postAnswer.push(node.i);
    }
    
    postorder(node);
    
    return [preAnswer, postAnswer];
}