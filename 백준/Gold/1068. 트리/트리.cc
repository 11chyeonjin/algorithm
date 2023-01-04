#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[50];
int removedNode;
int root;

int result = 0;

void dfs(int a) {
  if (root == removedNode)
    return;
  
  if (!tree[a].size()) {
    result++;
    return;
  }

  for (int i = 0; i < tree[a].size(); i++) {
    if (tree[a][i] != removedNode)
      dfs(tree[a][i]);
    else {
      if (tree[a].size() == 1)
        result++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  int tmp;
  
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    if (tmp == -1) {
      root = i;
      continue;
    }
    tree[tmp].push_back(i);
  }
  cin >> removedNode;

  dfs(root);

  cout << result;

  return 0;
} 