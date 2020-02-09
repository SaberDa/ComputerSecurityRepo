#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void frequence(string s) {
    unordered_map<char, int> m;
    for (auto i : s) m[i]++;
    auto comp = [](pair<int, char>& a, pair<int, char>& b){return a.first < b.first;};
    priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> pq(comp);
    for (auto i : m) pq.push({i.second, i.first});
    auto p = pq.top();
    cout << p.first << " " << p.second << endl;
    // while (!pq.empty()) {
    //     auto p = pq.top();
    //     pq.pop();
    //     cout << p.first << " " << p.second << endl;
    // }
    
}

void seperate(string s, int key) {
    string set1 = "";
    string set2 = "";
    string set3 = "";
    string set4 = "";
    string set5 = "";

    for (int i = 0; i < s.length(); i++) {
        int cur = i % key;
        switch (cur)
        {
        case 0:
            set1.push_back(s[i]);
            break;
        case 1:
            set2.push_back(s[i]);
            break;
        case 2:
            set3.push_back(s[i]);
            break;
        case 3:
            set4.push_back(s[i]);
            break;
        case 4:
            set5.push_back(s[i]);
            break;
        
        default:
            break;
        }
    }

    frequence(set1);
    cout << "-------------------" << endl;
    frequence(set2);
    cout << "-------------------" << endl;
    frequence(set3);
    cout << "-------------------" << endl;
    frequence(set4);
    cout << "-------------------" << endl;
    frequence(set5);

    // cout << set1 << endl;
    // cout << " " << endl;
    // cout << set2 << endl;
    // cout << " " << endl;
    // cout << set3 << endl;
    // cout << " " << endl;
    // cout << set4 << endl;
    // cout << " " << endl;
    // cout << set5 << endl;
}



int main() {

    string s = "loqfmkhvnvlpkyiloigaszzrgwpdrhxywzefpvgijumgwgbzpijlxbvllzfjgybuiflelsjrbvqwzbvqwhvqslometmitvgsaqbrkymsyklbbhazkhwkhenzwvnfxgyqrwvlvvkjhbvrytwgmguxvglbzrwlhzfefkxesvbkrvkhtysxaprqtharhguqypwniypqvjgeaumqtjvxrvlfwswgugglsaenwzhkxivhvqjwukrhtfkemepvnpkhxcejlvgpqdweoauossjuwexzrweiszuhvvlzbykkqpxsawewzpxfsffxvglbzrwwubrvlhqaqwubjekcqpxatqmivympifatlmfhunngykbvhvznxwzmpyjpblfjliplswxnvwubycauzrxssqnxavvssjapryhjwzmfnkbqwkgglwpvgijcqravpovxsskbtalabjmuzrpwharhxptzwhlzfsfhtsmfhvpmsslnxsvvrrllzgeauurrlpvqykazlrgaiopwzmzeasacekzebvvziahgaprvaunbvehbvsfhzrtgybrhgumuyfkzrhllznfqamfsxkigeauiypzhdrfwlvfxgsmaetvcgjgbzgcyponfqamflscmoiwuunhwwcopajabjsyunmfzbeistxhfdpknxavvfazpkuejlvrzwyzrxajmaxsiwhxkjwyhauoyikzmfxsitvwzllzivpibzwyiegsumwsmyvnpazbvgkjzhtdlanvwwcopazpvrykizeypvthsaisvgtbumkazbzwhaaiozxntwyanrvumjwuoiarwsapedsbuikawyifzwacvhbnaaaptvwhbeidpauefkjnvwsgpsfjmnpwkkbrllucxxvzusdsgjsgkbuiflelsjrbvqwzqfwzhzvrybvplsyqgetsmpsetmaxktiqiaumzeasaoildmrrlomrblyibvvpvnvasgfyujmfwxbtcvgkcpijzkbxlycqmfhvqwgugfxmkqbggjpnmjdwzefhultszknplomjekoqaklvvcskamztzhavdwzbuelycqmfoiqyfrqahovzqwxvzcvgtqaifaipxjlafhaympxgyiahhywqyulznryltvrsqwymwhajidsifjgyiamdskbrulqiivwtnrlvjhmdkippwvxnxjhubzaliesmulwsdpmgmelunksgqaikzizjjphrpdamnwwzbuikldrrevagsmaznkwvcfxzpvtwoltrejumqjjvuglwzwaczhkxjjphrpdkmppaumqxgymftgulgsibmfxavvfjjvuaelpwaedymimwdwapaumnfgbbglwwzbtjpmgcgmbeexmqpoauovrkawyifnwbhkmwexzlxhvhvarsxdzvxauoovwhbupwzanvlpkyikhjbylzkhxlsmoylabuelpnvxaudbpnllnrqvbuijpvqykazlagbtqfwjwawakmeivdmypopbumfaprfgbvqejpmfsxuweqssebvcwtngwzvvtauonpkvlrgdpvvryawpsetmaxepkuewskvihsgnrvizbsczjnvflabjlomgmelanrvciemwagfedlffxwkunrsdiflauogsfwwfxwkqgsjymftgulfxzhbglwwicijkwrwfvbcijtqgvwwwexwyagstymnolomyeopvcyjzcvxgmagsjpmfawumiijlvpsmyitisugbrwawfxwhtqsuburrlzvnxavvnpwjwasefiahtbavrwzarhaawekjlofgzumvhwyeemllavrsumzeasbbrsaqbrsszrzalebrdpvrlgdmiijdprrvvkhqwubfqsrmglwpzjeqpvgslomcytsqphgtivrgyieiklvgxgbajisymjmloqasmyzvkzaagsjlxbvlvvglwttrecznesejwztsuqrwsultsnlzaqwubnkwukvikhzrrgacaggtubrgcmeqsugqiuhlrwkbkupwhsflscmcvwzmaxwkvrakvztefphnxavvfaaapnaakmeefnmbjupzpyezbnrulaglsaknpdmwexzlugswemegazmwyvnurrldmnwklafisjpfilvnseuaavrvpdvhmhtycaubumkpvfxsukrxzlzrpwharsxkwpyelvgwohanrwcmaxloighwtiahwkkbzwyitisulglwpvssjtigmgujesmnpgxgsqtlloifwlpzeivkqfgmzavsfhjbylhpbwlvnyiypbvqsamvwkbmfxzhbnpkvenvjhvgivjwiijhorxzpavwsuwglwyiexajtrxzloesopvthvvagljligyfrvbafhbgeurmewzhdrfwlvgikaqaklomqixlvfikvnpsewiamwzbuelycagjpbvgssxnvlzwsxzlqaxwyvrxhvafmtsggsxpohvwvcglgdbbxsrmglwtlbafjgoijzmpyjpblipwmextycpikjpaialzjejumqxmlaqeqsiekwuigmguagellacijoicwuoqaegyzhwkpinvwaprparmycubtcvaaauikbotikamqrsaqbrkaigisjbbvkhzrkgpvtxgwzbfwawsmfkerecumfwwzqaedswssmybrgzuwysypmfwsplgvscqfwepbuwwuqbvklkhvaageikliegzlvtmflmeelazvtopzrxzlgjefabbofvejlsaknrtllbrwuwgsfsgvrlomrzwubbjsjgoijdiefmaixmflbvgohznwoltylwawyhllkurwdajsjslglwlifmwzbjeqawgecliaildweogmnglwpvgijumgmkdqglskqfxjpjhxwklrrahtbjklzimuligxsjsfgzumvijzivhsulfselwsxzlbnvylbrhuvucefpmfvwjmaxdfpnzwimrrzpbjmlolqskhbgeuraglsaieikpoamxpknrlsgyejnmepguorvdhagmfniahevzrwgwpvwlpknxwkbuefimssjlbuisabngczbltajiypqyiztmwbbehhzgmubtnvdldrplomawlvxglwfzrwmtmnxloiglanprvdldrpsulglwukbrlpvhijhucmfnccekpnglwhbgeurmewsymysgrqakxvzglwumgagysfiphkgtgpvgsxmivpmymfgzumvijzxrgmsigivaprelaipokbarqmsbvtdldrglvzfjgykvryaiekwaagsvlxysqhtysxaprmjkmsifzmfxzbaqmkjtbwauoglwpzpehhjvpaaqrwtlknyklbuisabngclzfazlzretvcgwsymhrcuwjrhvbrrlpiyxsyorxkjiahguwglauogsohzqxzlubjxzkurwpmewsplglwkigeklmzwlvqahajigiuoqaeazjrlaulglwtjhxaaacskzqopwawqmkncvwwaprggbvgvqvnbvanqahvvanrvvbuijhbgeuraumlympsjkprmyobfmfaprwwjwahibiexwywsxzpalisyixeehqeihvzgivklbwsabngczzbwwaerrlfbuvwlxrvulvgsnlzglwuczfwyzrggylrhauyhejlzssmybjslowhwsulnrvmqsxwlvnrvdmoehwtvgsaqbrsabngczqagjlifivaerrlfavbhlzpifabnvylbfwmmnrvwkitvwhbrvfbuoijvneihlighvvanxlhkxwldmaxquqaiguiiijhorqmsbvzwjbbvwkigxsjsfmfjzrekllnwvplziyhigxsjsfsxtweiloiasflphrvlzqktwahwauofmewtrelaiponlkgsjzxbwkpjyigyvbxkaigisjbbvkhzrtjvjnfdftbscpvtelhvhqtlzbjvpnsijlvgasfagsvpanfdlxnvlzweedswsxzlqaxwyvrxuvuzifamqtsbtzsuricilyqfggpviifawesxaprhgtivrfhurwqzbrqubzeifatlgzpmswupmaxazbnxlozrelzbbtvkwfmkvvrsxaprasfagsvvbuelhvqmovcyhatitmflagellipxgyajsmslnxlhkxvgbbvryzgfxwtanwoltylwawyhllkurwdajsjslglwhbgeurajsmsloievagixmmpxacmnkspvfxkoieivjwzqguaglwwcopajzrwgbzpikvvglwdmofmaxrshsmpsmsltsthkxxgaprwqzbrqgmxnvlpbvsfpvtxzlqaxwyvrxevkxehlbemkzctkwzbrhlowfioowuenlbuiaywjrhywgiuamqrwaebvcdqypuvvgmfbmgszhdrmfamerwaipgwzanxsrmqsouwsxzlmaxaymvrllzailpaaslnwvryawuehwmaggubrrvllzejaqaqurmncklkhvaagnhnvknxwhbnostivfwjihwwpbfeoowyitbvplgmvrxovzxwsullsmymaslnwvryawgeclqghgdvhrdlafcgbbnowkwjrsstglwjqegmpbfcgbknrlhsrhgdvnggtxnrqhvbvyhvvdsaqbrgyxnvlvnnkgcmerelvgfmagbyuhvgvwhtyclhsrhgdvglwpvgijumgekheusdlkbqebvvgsaqbrksqaokhzrxgvevhwzxeisknbvsntbfssigxsjsgskbkpiwkprxgslgiuovrakdwepvaprvwhzreuvccpwkwmifameetpbpmjjcvxkmzbqkhvsvsukvwuviysflbblguoxsfniahlvslssulbxzlzcpsjmfxzltnvylagrwaebvcsilijhbgeurafiwuabjsyictjviplauosmnlphrvymqktwanvwhvbvvlzbjehoamlblrwehtyijapnrlomoefkevhlokntsjqgclomyejnmfxlyiawaaxesnplrvkhvqmkwazefhorrgamqxatunxzlefzajmcvwzqqifawsxzlqagswahpswzbhmjbymfligmewmezsdqglhywcijklbwhywgiuaqbrkpvcpsjmzskaigxsjsfagbtqfwzbbthllvrlomvvlyipokomgsdkbrgzumjwovzyhovzfxuharwulvnvavaglwswfwgmcgmdpbvikhvqielztifjgfijcqpikymfydaqakxywzefpvgijumgxsrmqsoukbydkxesevbrxzlmfxsitvwztmaxgmuvpaaqnkjvccwsulcskzqopqhjeisrlbafvnfsupmgcohzaivtqplsltcelamewgukrsgmxymplzvqsnqaiqvcerwpoufgyarbuscqmfngbyxywztjvbrglpwafwjihwwfwhlscmasjlabyjjmfxgzpnvwaprvwzxbrkpjvpaaggskhnrkmhzqxzlqaxwyvrxxywzelaipokoifjsstrrdhztidfwawwydvgwwzbzakmewzlbbpvamplflefagytqmfaprwzvzgvmujnrcziahgaprvtbavrwzarwuvcyhkbageaukbrkplrvsitriuvvbqajtbwklavjlomvrllzaildmaxvveaefkbuiqswfxwwprqwyiyxjhvfeuaqbrsslnxshsnqspazgclilwmnorwllloylswakllzzsmaitikhzrrlhxestsmz";
    int key = 5;

    seperate(s, key);
    




    return 0;
}