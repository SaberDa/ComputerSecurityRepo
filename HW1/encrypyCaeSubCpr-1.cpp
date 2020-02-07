#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Encryp
// f(a) = (a + 3) mod 26
string Alphabet = "abcdefghijklmnopqrstuvwxyz";

string psw(string s, int key) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = ((s[i] - 'a') + key) % 26 + 'a';
    }
    return s;
}

// Decrypt
// f(a) = (a + 23) mod 26
string unpsw(string s, int key) {
    key = 26 - key;
    for (int i = 0; i < s.length(); i++) {
        s[i] = ((s[i] - 'a') + key) % 26 + 'a';
    }
    return s;
}

int main() {

    string s = "theshadowofthemoonsweptacrosstheglobefromhongkongtothetexaspanhandleasarareannularsolareclipsebeganmondaymorninginasiaandtraversedthepacificthesunappearedasathinringbehindthemoontopeopleinanarrowpathalongthecenterofthetrackwhichbeganinsouthernchinaheavycloudsobscuredtheviewinhongkongbutresidentsoftokyoandothercitieswereabletogetaspectacularviewforaboutfourminutesaroundseventhirtytwoammondaysixthirtytwopmetsundayeventswereheldatschoolsandmuseumsinjapanwhilemanymorepeopletookintheunusualastronomicaleventathomeoronstreetcornersafterwhizzingacrossthepacifictheshadowemergedovernortherncaliforniaandsouthernoregonwherethousandsofpeopleattendedpartiestowatchtheeventthefirsttoappearintheunitedstatessincenineteenninetyfourexpertswarnedthathopefulviewersshouldnotpeerupattheskywithoutspecialviewingequipmentsincelookingatthesunwiththenakedeyecancauseblindnessderekralstonaprofessionalphotographersaidheusedaweldingfiltertocaptureadirectviewofeclipseinthefoothillsaboveorovillecaliforniahesharedthephotooncnnireportnotingtheratherslimswathoftheglobewhocouldseetheimpactoftheeclipseralstonsaidhewantedtoenabletherestoftheworldtoseehowclearitlookedtothoseofuswhowerefortunateenoughtoseeitthesliverofsunshinethentraveledsoutheastacrosscentralnevadasouthernutahandnorthernarizonaandthennewmexicoitpassedoveralbuquerquenewmexicoaboutseventhirtyfourpmninethirtyfourpmetbeforepeteringouteastoflubbocktexasaccordingtonasa";

    int key = 4;

    s = psw(s, key);

    cout << s << endl;

    return 0;
}