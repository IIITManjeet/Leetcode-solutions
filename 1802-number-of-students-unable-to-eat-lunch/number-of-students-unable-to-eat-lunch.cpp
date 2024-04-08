class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>sand;
        int n=students.size();
        queue<int>stud;
        for(int i=0;i<n;i++){
            stud.push(students[i]);
            sand.push(sandwiches[n-i-1]);
        }
        int notStud=0;
        while(sand.size()>0 && notStud<stud.size()){
            if(stud.front()==sand.top()){
                stud.pop();
                sand.pop();
                notStud=0;
            }else{
                stud.push(stud.front());
                stud.pop();
                notStud++;
            }
        }
        return stud.size();
    }
};