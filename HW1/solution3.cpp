#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

void frequencyByInt(string s1, string s2) {

    unordered_map<char, int> m;
    for (auto i : s1) m[i]++;
    for (auto i : s2) m[i]++;

    auto comp = [](pair<int, char>& a, pair<int, char>& b){return a.first > b.first;};
    priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> pq(comp);
    for (auto i : m) pq.push({i.second, i.first});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        cout << p.first << " " << p.second << endl;
    }

}

void frequencyByChar(string s1, string s2) {

    unordered_map<char, int> m;
    for (auto i : s1) m[i]++;
    for (auto i : s2) m[i]++;

    auto comp = [](pair<char, int>& a, pair<char, int>& b){return a.first < b.first;};
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
    for (auto i : m) pq.push({i.first, i.second});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        cout << p.first << " " << p.second << endl;
    }

}

string psw(string s, int key) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = ((s[i] - 'a') + key) % 26 + 'a';
    }
    return s;
}

string tranfer(string s) {
    for (int x = 0; x < s.length(); x++) {
        switch (s[x])
        {
        case '+':
            s[x] = 'a';
            break;

        case '_':
            s[x] = 'b';
            break;

        case '*':
            s[x] = 'c';
            break;

        case '&':
            s[x] = 'd';
            break;

        case '@':
            s[x] = 'e';
            break;

        case '=':
            s[x] = 'f';
            break;

        case '^':
            s[x] = 'g';
            break;

        case 'c':
            s[x] = 'h';
            break;

        case '%':
            s[x] = 'i';
            break;

        case 'z':
            s[x] = 'j';
            break;

        case '#':
            s[x] = 'k';
            break;

        case '\'':
            s[x] = 'l';
            break;

        case '~':
            s[x] = 'm';
            break;

        case '!':
            s[x] = 'n';
            break;

        case ':':
            s[x] = 'o';
            break;

        case '}':
            s[x] = 'p';
            break;

        case ')':
            s[x] = 'q';
            break;

        case '(':
            s[x] = 'r';
            break;

        case '`':
            s[x] = 's';
            break;

        case '?':
            s[x] = 't';
            break;

        case '>':
            s[x] = 'u';
            break;

        case '<':
            s[x] = 'v';
            break;

        case '/':
            s[x] = 'w';
            break;

        case '|':
            s[x] = 'x';
            break;

        case '.':
            s[x] = 'y';
            break;

        case ' ':
            s[x] = 'z';
            break;

        default:
            break;
        }
    }
    cout << s << endl;
    return s;
}


int main() {

    string s1 = "#@.`+(@}%@*@`:=%!=:(~+?%:!?c+?&@?@(~%!@?c@:>?}>?=(:~+!@!*(.}?%:!:(&@*(.}?%:!}(:*@``+`%!^'@*%}c@(*+!}(:&>*@+!+'~:`?'%~%?'@``!>~_@(:=&%==@(@!?:>?}>?`/%?c&%==@(@!?#@.<+'>@`+'':/%!^`@*>(@*:~~>!%*+?%:!@<@!%=?c@*%}c@(%?`@'=%`#!:/!?:c:`?%'@?c%(&}+(?%@`%?~%^c?`>(}(%`@.:>?:#!:/?c+?+'~:`?+''*%}c@(`+(@}>_'%`c@&%!?c@`*%@!?%=%*}(@``:(%!`?+!&+(&`&:*>~@!?`c+<%!^?c@~+<+%'+_'@=:(/%&@`}(@+&`*(>?%!.+'':/`~+!.}@:}'@?:*c@*#?c+??c@.+(@`@*>(@+!&&:!:?*:!?+%!/@+#!@``@`/c%*c*:>'&_@@|}':%?@&?:*:~}(:~%`@?c@`@*>(%?.:=?c@&+?+@!*(.}?@&>`%!^?c+?*%}c@(+*:~}>?@(@!*(.}?%:!#@.%`!:?c%!^~:(@?c+!+`?(%!^:=_%?`/c@(@@+*c_%?*+!c+<@+<+'>@:=@%?c@( @(::(:!@?c@!>~_@(:=}:``%_'@<+'>@`=:(+#@.%``%~}'.?c@?:?+'!>~_@(:=<+'>@`?c+??c@#@.*+!c+<@`::>(:!@_%?':!^#@.*+!:!'.c+<@?/:}:``%_'@<+'>@` @(:+!&:!@%=/@*c::`@?:c+<@+?/:_%?#@.%?*:>'&c+<@:!@:==:>(}:``%_'@<+'>@` @(: @(: @(::!@:!@ @(:+!&:!@:!@%!=+*?@<@(.?%~@/@%!*(@+`@?c@'@!^?c:=?c@#@._.:!@_%?/@&:>_'@?c@!>~_@(:=}:``%_'@#@.``:+?c(@@_%?#@.c+`@%^c?}:``%_'@<+'>@` @(: @(: @(: @(: @(: @(: @(::!@ @(::!@ @(: @(::!@:!@:!@ @(: @(";
    string s2 = "::!@ @(::!@:!@:!@ @(:+!&:!@:!@:!@:!@?c@?:?+'!>~_@(:=#@.`*+!_@/(%??@!%!`*%@!?%=%*=:(~+`?/:#@.'@!^?c`:+#@./%?c+'@!^?c:=@%^c?c+`?/@!?.@%^c??c+?%`?/:c>!&@(@&+!&=%=?.`%|<+'>@`_>?c:/':!^`c:>'&+#@._@c:/`c:(?%`?::`c:(??c@}(:_'@~/%?c`c:(?#@.``c:(?#@.`+(@<>'!@(+_'@?:/c+?%`#!:/!+`+_(>?@=:(*@+??+*#z>`?'%#@.:>'@+(!@&%!/@@#?/:+_:>?}+``/:(&`+_(>?@=:(*@+??+*#%`/c@(@+*:~}>?@(:(+!>~_@(:=*:~}>?@(`?(.@<@(.}:``%_'@<+'>@=:(+#@.>!?%'?c@.}(:&>*@(@*:^!%`+_'@}'+%!?@|?`%!*@*:~}>?@(`*+!/:(#?c(:>^c#@.<+'>@`@|?(@~@'.(+}%&'.#@.`~>`?_@`>==%*%@!?'.':!^?c+??c@.:==@(+<@(.'+(^@!>~_@(:=}:``%_'@<+'>@`#@.`~+._@#!:/!?:?c@>`@(%!?c@=:(~:=}+``/:(&`:(?c@.~+._@`?:(@&%!+*:~}>?@(`c+(&/+(@`>*c+`?c@&@*(.}?%:!#@.``?:(@&:!+&<&}'+.@(?c+?+'':/%??:}'+.?c@@!*(.}?@&&+?+`?:(@&:!?c@~:<%@&%`#:(?c@.*+!_@^@!@(+?@&_.+*:~}>?@(+`+!&/c@!?c@.+(@!@@&@&`>*c+`*:!&>*?%!^+`@*>(@?(+!`+*?%:!:!+`c:}}%!^`%?@!@|?.:>'''@+(!+_:>??c@#@.&%`?(%_>?%:!}(:_'@~`:>(*@c??}`///:}@!@&>";
    
    // string s = s1 + s2;
    // s = psw(s, 24);
    // cout << s << endl;

    // frequencyByChar(s1, s2);

    s1 = tranfer(s1);
    s2 = tranfer(s2);


    return 0;
}