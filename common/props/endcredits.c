float calculateYPosition(int index);

int creditGroup0Active = 1;
int creditGroup1Active = 0;
int creditGroup2Active = 0;
int creditGroup3Active = 0;
int creditGroup4Active = 0;
int creditGroup5Active = 0;
int creditGroup6Active = 0;

float GlobalY = 0.0f;
int Group0Reached = 0;
int Group1Reached = 0;
int Group2Reached = 0;
int Group3Reached = 0;
int Group4Reached = 0;
int Group5Reached = 0;
int Group6Reached = 0;

float calculateYPosition(int index) {
    return (-0.3f * (float)index) + GlobalY;
}

void drawSandeshReference()
{
    void thankYou(char*, float, int);

    float speed = 0.003;

    thankYou("Thank You", speed, 1);
}

void groupLeader(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.6, y, 0.0f};
    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
}

void shaileshUbhe(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.55, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void projectLead(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.6, y, 0.0f};
    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
}

void nikhilSathe(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.5, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void groupMembers(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.6, y, 0.0f};
    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
}

void ayushJaiswal(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.5, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void bhagyashreeChavan(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.7, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void bhushanRane(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.5, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void imranPathan(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.5, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void himanshuChowdhary(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.75, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void nitinKolapkar(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.6, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void vishalKamble(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.6, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void vaibhavIle(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.5, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void radhikaVishwakarma(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.80, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void drShripadBhatlawande(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-1.0, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void vighneshNair(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.55, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void vinayakMali(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.55, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void specialThanks(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.85, y, 0.0f};
    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
}

void ramamam(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.7, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void pradhnaymam(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.8, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void mam(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.3, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void yogeshwarsir(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.85, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void radhikamam(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.85, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void allRTRGroups(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.55, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void ignitedBy(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.5, y, 0.0f};
    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
}

void sirName(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.95, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void filmDivisionSandesh(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.9, y, 0.0f};
    drawWord(name, 0.13f, start, whiteColor, 10.0f, 0.050);
}

void link(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    MY_POINT start = {-0.7, y, 0.0f};
    drawWord(name, 0.13f, start, whiteColor, 10.0f, 0.050);
}

void thankYou(char *name, float speed, int index)
{
    float y = calculateYPosition(index);
    
    if (y > 0.5f) {
        y = 0.5f;
    }
    
    MY_POINT start = {-0.45, y, 0.0f};
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
}

void drawCreditsGroup0(float speed)
{
    filmDivisionSandesh("Film Division - Sandesh", speed, 1);
    link("Link in Description", speed, 2);
    if (GlobalY > 1.05f) Group0Reached = 1;
}

void drawCreditsGroup1(float speed)
{
    ignitedBy("Ignited By", speed, 1);
    sirName("Dr. Vijay D. Gokhale Sir", speed, 2);
    if (GlobalY > 1.05f) Group1Reached = 1;
}

void drawCreditsGroup2(float speed)
{
    specialThanks("Special Thanks to -", speed, 1);
    ramamam("Rama Gokhale Madam", speed, 2);
    pradhnaymam("Pradnya Vijay Gokhle", speed, 3);
    mam("Madam", speed, 4);
    yogeshwarsir("Yogeshwar Shukla Sir", speed, 5);
    radhikamam("Radhika Shukla Madam", speed, 6);
    allRTRGroups("RTR Group Leaders", speed, 7);
    if (GlobalY > 1.65f) Group2Reached = 1;
}

void drawCreditsGroup3(float speed)
{
    groupLeader("Group Leader", speed, 1);
    shaileshUbhe("Shailesh Ubhe", speed, 2);
    if (GlobalY > 1.05f) Group3Reached = 1;
}

void drawCreditsGroup4(float speed)
{
    groupMembers("Group Members", speed, 1);
    ayushJaiswal("Ayush Jaiswal", speed, 2);
    imranPathan("Imran Pathan", speed, 3);
    vaibhavIle("Vaibhav Ile", speed, 4);
    bhagyashreeChavan("Bhagyashree Chavan", speed, 5);
    if (GlobalY > 1.05f) Group4Reached = 1;
}

void drawCreditsGroup5(float speed)
{
    vighneshNair("Vighnesh Nair", speed, 1);
    radhikaVishwakarma("Radhika Vishwakarma", speed, 2);
    vishalKamble("Vishal Kamble", speed, 3);
    nitinKolapkar("Nitin Kolapkar", speed, 4);
    bhushanRane("Bhushan Rane", speed, 5);
    if (GlobalY > 1.05f) Group5Reached = 1;
}

void drawCreditsGroup6(float speed)
{
    himanshuChowdhary("Himanshu Chowdhary", speed, 1);
    vinayakMali("Vinayak Mali", speed, 2);
    drShripadBhatlawande("Dr. Shripad Bhatlawande", speed, 3);
    nikhilSathe("Nikhil Sathe", speed, 4);
    thankYou("Thank You", speed, 5);
    if (GlobalY > 1.05f) Group6Reached = 1;
}

void updateCreditsAnimation()
{
    float speed = 0.003;
    
    if (creditGroup0Active)
        drawCreditsGroup0(speed);

    if (creditGroup1Active)
        drawCreditsGroup1(speed);
        
    if (creditGroup2Active)
        drawCreditsGroup2(speed);
        
    if (creditGroup3Active)
        drawCreditsGroup3(speed);
        
    if (creditGroup4Active)
        drawCreditsGroup4(speed);
        
    if (creditGroup5Active)
        drawCreditsGroup5(speed);
        
    if (creditGroup6Active)
        drawCreditsGroup6(speed);
        
    if (creditGroup0Active && Group0Reached == 1) {
        creditGroup1Active = 1;
        creditGroup0Active = 0;
        GlobalY = 0.0f;
        Group0Reached = 0;
    }
    
    if (creditGroup1Active && Group1Reached == 1) {
        creditGroup2Active = 1;
        creditGroup1Active = 0;
        GlobalY = 0.0f;
        Group1Reached = 0;
    }
    
    if (creditGroup2Active && Group2Reached == 1) {
        creditGroup3Active = 1;
        creditGroup2Active = 0;
        GlobalY = 0.0f;
        Group2Reached = 0;
    }
    
    if (creditGroup3Active && Group3Reached == 1) {
        creditGroup4Active = 1;
        creditGroup3Active = 0;
        GlobalY = 0.0f;
        Group3Reached = 0;
    }
    
    if (creditGroup4Active && Group4Reached == 1) {
        creditGroup5Active = 1;
        creditGroup4Active = 0;
        GlobalY = 0.0f;
        Group4Reached = 0;
    }
    
    if (creditGroup5Active && Group5Reached == 1) {
        creditGroup6Active = 1;
        creditGroup5Active = 0;
        GlobalY = 0.0f;
        Group5Reached = 0;
    }
    
    GlobalY += speed;
}

void drawMemberNames()
{
    void drawCreditsGroup1(float);
    void drawCreditsGroup2(float);
    void drawCreditsGroup3(float);
    void drawCreditsGroup4(float);
    void drawCreditsGroup5(float);
    void drawCreditsGroup6(float);
    void updateCreditsAnimation();

    updateCreditsAnimation();
}
