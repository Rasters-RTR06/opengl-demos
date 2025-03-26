
void drawSandeshReference()
{
    // Local function declarations
    void thankYou(char*, float);

    // Variable declaration's
    float speed = 0.008;

    thankYou("Thank You", speed);
}




void drawMemberNames()
{
        // Local function declaration's
        void groupLeader(char *, float);
        void shaileshUbhe(char *, float);
        void projectLead(char *, float);
        void nikhilSathe(char *, float);
        void groupMembers(char *, float);
    
        void ayushJaiswal(char *, float);
        void bhagyashreeChavan(char *, float);
        void bhushanRane(char *, float);
        void imranPathan(char *, float);
        void himanshuChowdhary(char *, float);
        void nitinKolapkar(char *, float);
        void vishalKamble(char *, float);
        void vaibhavIle(char *, float);
        void radhikaVishwakarma(char *, float);
        void drShripadBhatlawande(char *, float);
        void vighneshNair(char *, float);
        void vinayakMali(char *, float);
    
        void ignitedBy(char *, float);
        void sirName(char *, float);
        void specialThanks(char *, float);
        void ramamam(char *, float);
        void pradhnaymam(char *, float);
        void mam(char *, float);
        void yogeshwarsir(char *, float);
        void radhikamam(char *, float);
        void allRTRGroups(char *, float);

        void filmDivisionSandesh(char*, float);
        void link(char*, float);
        void thankYou(char*, float);

        // Local variable declaration's
        float speed = 0.008;
    
        // Code

    groupLeader("Group Leader", speed);
    shaileshUbhe("Shailesh Ubhe", speed);
    projectLead("Project Lead", speed);
    nikhilSathe("Nikhil Sathe", speed);
    groupMembers("Group Members", speed);

    ayushJaiswal("Ayush Jaiswal", speed);
    bhagyashreeChavan("Bhagyashree Chavan", speed);
    bhushanRane("Bhushan Rane", speed);
    imranPathan("Imran Pathan", speed);
    himanshuChowdhary("Himanshu Chowdhary", speed);
    nitinKolapkar("Nitin Kolapkar", speed);
    vishalKamble("Vishal Kamble", speed);
    vaibhavIle("Vaibhav Ile", speed);
    radhikaVishwakarma("Radhika Vishwakarma", speed);
    drShripadBhatlawande("Dr. Shripad Bhatlawande", speed);
    vighneshNair("Vighnesh Nair", speed);
    vinayakMali("Vinayak Mali", speed);

    specialThanks("Special Thanks to -", speed);
    ramamam("Rama Gokhale Madam", speed);
    pradhnaymam("Pradnya Vijay Gokhle", speed);
    mam("Madam", speed);
    yogeshwarsir("Yogeshwar Shukla Sir", speed);
    radhikamam("Radhika Shukla Madam", speed);

    allRTRGroups("All RTR Groups", speed);

    ignitedBy("Ignited By", speed);
    sirName("Dr. Vijay D. Gokhale Sir", speed);

    filmDivisionSandesh("Film Division - Sandesh", speed);
    link("Link in Description", speed);
    thankYou("Thank You", speed);
}


void groupLeader(char *name, float speed)
{
    // Variable declaration's
    static float y = -0.1;
    MY_POINT start = {-0.6, y, 0.0f};

    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
    y = y + speed;
}

void shaileshUbhe(char *name, float speed)
{
    // Variable declaration's
    static float y = -0.4;
    MY_POINT start = {-0.55, y, 0.0f};

    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void projectLead(char *name, float speed)
{
    // Variable declaration's
    static float y = -0.8;
    MY_POINT start = {-0.6, y, 0.0f};

    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
    y = y + speed;
}

void nikhilSathe(char *name, float speed)
{
    // Variable declaration's
    static float y = -1.1;
    MY_POINT start = {-0.5, y, 0.0f};
    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void groupMembers(char *name, float speed)
{
    // Variable declaration's
    static float y = -1.5;
    MY_POINT start = {-0.6, y, 0.0f};

    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
    y = y + speed;
}

void ayushJaiswal(char *name, float speed)
{
    // Variable declaration's
    static float y = -1.8;
    MY_POINT start = {-0.5, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void bhagyashreeChavan(char *name, float speed)
{
    // Variable declaration's
    static float y = -2.1;
    MY_POINT start = {-0.7, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void bhushanRane(char *name, float speed)
{
    // Variable declaration's
    static float y = -2.4;
    MY_POINT start = {-0.5, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void imranPathan(char *name, float speed)
{
    // Variable declaration's
    static float y = -2.7;
    MY_POINT start = {-0.5, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void himanshuChowdhary(char *name, float speed)
{
    // Variable declaration's
    static float y = -3.0;
    MY_POINT start = {-0.75, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void nitinKolapkar(char *name, float speed)
{
    // Variable declaration's
    static float y = -3.3;
    MY_POINT start = {-0.6, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void vishalKamble(char *name, float speed)
{
    // Variable declaration's
    static float y = -3.6;
    MY_POINT start = {-0.6, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void vaibhavIle(char *name, float speed)
{
    // Variable declaration's
    static float y = -3.9;
    MY_POINT start = {-0.5, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void radhikaVishwakarma(char *name, float speed)
{
    // Variable declaration's
    static float y = -4.2;
    MY_POINT start = {-0.80, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void drShripadBhatlawande(char *name, float speed)
{
    // Variable declaration's
    static float y = -4.5;
    MY_POINT start = {-1.0, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void vighneshNair(char *name, float speed)
{
    // Variable declaration's
    static float y = -4.8;
    MY_POINT start = {-0.55, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void vinayakMali(char *name, float speed)
{
    // Variable declaration's
    static float y = -5.1;
    MY_POINT start = {-0.55, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void specialThanks(char *name, float speed)
{
    // Variable declaration's
    static float y = -5.5;
    MY_POINT start = {-0.85, y, 0.0f};

    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
    y = y + speed;
}

void ramamam(char *name, float speed)
{
    // Variable declaration's
    static float y = -5.8;
    MY_POINT start = {-0.7, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void pradhnaymam(char *name, float speed)
{
    // Variable declaration's
    static float y = -6.1;
    MY_POINT start = {-0.8, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void mam(char *name, float speed)
{
    // Variable declaration's
    static float y = -6.4;
    MY_POINT start = {-0.3, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void yogeshwarsir(char *name, float speed)
{
    // Variable declaration's
    static float y = -6.7;
    MY_POINT start = {-0.85, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void radhikamam(char *name, float speed)
{
    // Variable declaration's
    static float y = -7.0;
    MY_POINT start = {-0.85, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void allRTRGroups(char *name, float speed)
{
    // Variable declaration's
    static float y = -7.3f;
    MY_POINT start = {-0.55, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void ignitedBy(char *name, float speed)
{
    // Variable declaration's
    static float y = -8.8;
    MY_POINT start = {-0.5, y, 0.0f};

    drawWord(name, 0.2f, start, color, 10.0f, 0.050);
    y = y + speed;
}

void sirName(char *name, float speed)
{
    // Variable declaration's
    static float y = -9.1;
    MY_POINT start = {-0.95, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void filmDivisionSandesh(char *name, float speed)
{
    // Variable declaration's
    static float y = -10.5;
    MY_POINT start = {-0.9, y, 0.0f};

    drawWord(name, 0.13f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void link(char *name, float speed)
{
    // Variable declaration's
    static float y = -10.8;
    MY_POINT start = {-0.7, y, 0.0f};

    drawWord(name, 0.13f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
}

void thankYou(char *name, float speed)
{
    // Variable declaration's
    static float y = -11.8;
    MY_POINT start = {-0.45, y, 0.0f};

    // Code
    drawWord(name, 0.15f, start, whiteColor, 10.0f, 0.050);
    y = y + speed;
    if(y > 0.0f)
        y = 0.0f;
}
