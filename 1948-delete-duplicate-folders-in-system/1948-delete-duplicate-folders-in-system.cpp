class Solution {
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        string name;
        bool deleted = false;
        TrieNode(string _name = "") : name(_name) {}
        ~TrieNode() {
            for (auto &p : children) delete p.second;
        }
    };
    
    void insert(TrieNode* root, vector<string>& path) {
        TrieNode* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder))
                node->children[folder] = new TrieNode(folder);
            node = node->children[folder];
        }
    }
    
    string serialize(TrieNode* node, unordered_map<string, vector<TrieNode*>>& seen) {
        if (node->children.empty()) return "";
        vector<pair<string, string>> subs;
        for (auto& p : node->children) {
            string ser = serialize(p.second, seen);
            subs.emplace_back(p.first, ser);
        }
        sort(subs.begin(), subs.end());
        string subStr;
        for (auto& [k, v] : subs)
            subStr += '(' + k + v + ')';
        seen[subStr].push_back(node);
        return subStr;
    }
    
    void markDeleted(unordered_map<string, vector<TrieNode*>>& seen) {
        for (auto& [key, nodes] : seen) {
            if (nodes.size() > 1 && !key.empty()) { 
                for (TrieNode* node : nodes)
                    node->deleted = true;
            }
        }
    }
    
    void collect(TrieNode* node, vector<string>& curr, vector<vector<string>>& ans) {
        if (node->deleted) return;
        if (!curr.empty())
            ans.push_back(curr);
        for (auto& [name, child] : node->children) {
            curr.push_back(name);
            collect(child, curr, ans);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for (auto& path : paths)
            insert(root, path);
        unordered_map<string, vector<TrieNode*>> seen;
        serialize(root, seen);
        markDeleted(seen);
        vector<vector<string>> ans;
        vector<string> curr;
        collect(root, curr, ans);
        delete root;
        return ans;
    }
};