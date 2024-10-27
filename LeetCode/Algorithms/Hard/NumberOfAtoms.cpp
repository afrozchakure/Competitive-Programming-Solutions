class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<int, int>> m; 

        int i = 0; 
        string count_str = "";
        int count = 0;
        while(i < formula.size()) {
            string count_str = "";
            if(formula[i] == '(') {
                stack.push({});
            } else if(formula[i] == ')') {
                curr_map = stack.top(); 
                stack.pop(); 

                count_str = "";
                while((i + 1) < formula.size() && isdigit(formula[i + 1])) {
                    count += formula[i + 1];
                    i += 1;
                }

                if(count_str.size() == 0) {
                    count = 1; 
                } else {
                    count = stoi(count_str);
                }

                for(auto &ele: cur_map) {
                    cur_map[ele] *= count; 

                    prev_map[ele] += cur_map[ele];
                }

                prev_map = stack.top(); 


                prev_map = stack.top(); 
            } else {
                char element = formula[i];
                string count_str = "";
                if((i + 1) < len(formula) && islower(formula[i + 1])) {
                    element = formula.substr(i, 2);
                }

                while(i + 1 < len(formula)) {
                    count_str += formula[i + 1];
                    i+=1;
                }

                int count = 0; 
                if(count_str.size() == 0) {
                    count = 1; 
                } else {
                    count = stoi(count_str);
                }

                map<int, int> curr_map = stack.top(); 
                curr_map[element] += count; 
            }
        }

        map<int, int> count_map = stk.top(); 
        string result = "";
        for(ele in count_map) {

            if(count_map[ele] == 1) {
                count = 0;
            } else {
                cunt = count_map[ele];
            }
            // count = count_map[ele]; 
            result = ele + to_string(count);
        }
        return result;
    }
};