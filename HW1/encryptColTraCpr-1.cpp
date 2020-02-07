#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string s = "theshadowofthemoonsweptacrosstheglobefromhongkongtothetexaspanhandleasarareannularsolareclipsebeganmondaymorninginasiaandtraversedthepacificthesunappearedasathinringbehindthemoontopeopleinanarrowpathalongthecenterofthetrackwhichbeganinsouthernchinaheavycloudsobscuredtheviewinhongkongbutresidentsoftokyoandothercitieswereabletogetaspectacularviewforaboutfourminutesaroundseventhirtytwoammondaysixthirtytwopmetsundayeventswereheldatschoolsandmuseumsinjapanwhilemanymorepeopletookintheunusualastronomicaleventathomeoronstreetcornersafterwhizzingacrossthepacifictheshadowemergedovernortherncaliforniaandsouthernoregonwherethousandsofpeopleattendedpartiestowatchtheeventthefirsttoappearintheunitedstatessincenineteenninetyfourexpertswarnedthathopefulviewersshouldnotpeerupattheskywithoutspecialviewingequipmentsincelookingatthesunwiththenakedeyecancauseblindnessderekralstonaprofessionalphotographersaidheusedaweldingfiltertocaptureadirectviewofeclipseinthefoothillsaboveorovillecaliforniahesharedthephotooncnnireportnotingtheratherslimswathoftheglobewhocouldseetheimpactoftheeclipseralstonsaidhewantedtoenabletherestoftheworldtoseehowclearitlookedtothoseofuswhowerefortunateenoughtoseeitthesliverofsunshinethentraveledsoutheastacrosscentralnevadasouthernutahandnorthernarizonaandthennewmexicoitpassedoveralbuquerquenewmexicoaboutseventhirtyfourpmninethirtyfourpmetbeforepeteringouteastoflubbocktexasaccordingtonasa";

    int size = 5;
    int length = s.length();
    int row = length / 5 + 1;
    int cur = 0;
    vector<vector<string> > res(row, vector<string>(size, "#"));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = s[cur++];
        }
    }

    vector<string> ans1;
    vector<string> ans2;
    vector<string> ans3;
    vector<string> ans4;
    vector<string> ans5;

    for (int i = 0; i < row; i++) {
        ans1.push_back(res[i][0]);
    }
    for (int i = 0; i < row-1; i++) {
        ans2.push_back(res[i][3]);
    }
    for (int i = 0; i < row-1; i++) {
        ans3.push_back(res[i][1]);
    }
    for (int i = 0; i < row-1; i++) {
        ans4.push_back(res[i][4]);
    }
    for (int i = 0; i < row-1; i++) {
        ans5.push_back(res[i][2]);
    }

    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i];
    }
    cout << " " << endl;

    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i];
    }
    cout << " " << endl;

    for (int i = 0; i < ans3.size(); i++) {
        cout << ans3[i];
    }
    cout << " " << endl;

    for (int i = 0; i < ans4.size(); i++) {
        cout << ans4[i];
    }
    cout << " " << endl;

    for (int i = 0; i < ans5.size(); i++) {
        cout << ans5[i];
    }
    cout << " " << endl;

    // for (int i = 0; i < res.size(); i++) {
    //     for (int j = 0; j < res[0].size(); j++) {
    //         cout << res[i][j];
    //     }
    //     cout << " " << endl;
    // }

    return 0;
}