
float charSpecing = 0.030f;
float titleHeight = 0.2f;
float subTitleHeight = 0.15f;
float yAnimatePosition = -1.0f;
float fArrowHeight = 0.2f;

COLOR RedColor = {1.0f, 0.0f, 0.0f, 0.0f};
COLOR WhiteColor = {1.0f, 1.0f, 1.0f, 0.0f};

// Struct for endcredits
typedef struct
{
    char *Name;
    COLOR textColor;
    float positionY;
    float height;
} EndCredits;

void ShowEndCredits(EndCredits endcredits[], int arrayLength)
{
    // Function declaration's
    void drawArrow(float, float, float, float);

    int i = 0;

    for (i = 0; i < arrayLength; ++i)
    {
        float center = (charSpecing - (getWordwidth(endcredits[i].Name, endcredits[i].height, charSpecing)) / 2.0f);

        if ((arrayLength == 1) && (endcredits[i].positionY > 0.0f))
            endcredits[i].positionY = 0.0f;

        MY_POINT start = {center, endcredits[i].positionY, 0.0f};

        drawWord(endcredits[i].Name, endcredits[i].height, start, endcredits[i].textColor, 8.0f, charSpecing);
    }

    // Arrow
    if (arrayLength != 1)
        drawArrow(0.1f, endcredits[i - 1].positionY - 0.2f, 1.0f, 0);
}

void drawMemberNames()
{

    // Local variable declaration's
    float y = yAnimatePosition;

    // Code

    // Clear OpenGl buufers
    glClear(GL_COLOR_BUFFER_BIT);

    EndCredits ProjectLead[2];
    EndCredits GroupLeader[2];
    EndCredits Members[13];
    EndCredits SpecialThanks[6];
    EndCredits SirName[2];
    EndCredits ThankYou[1];

    // Project Lead
    ProjectLead[0].Name = "Project Lead";
    ProjectLead[0].textColor = RedColor;
    ProjectLead[0].positionY = y;
    ProjectLead[0].height = titleHeight;

    y = y - titleHeight - charSpecing;

    ProjectLead[1].Name = "Nikhil Sathe";
    ProjectLead[1].textColor = WhiteColor;
    ProjectLead[1].positionY = y;
    ProjectLead[1].height = subTitleHeight;

    // Group Leader
    y = y - 2.0f - fArrowHeight;

    GroupLeader[0].Name = "Group Leader";
    GroupLeader[0].textColor = RedColor;
    GroupLeader[0].positionY = y;
    GroupLeader[0].height = titleHeight;

    y = y - titleHeight - charSpecing;

    GroupLeader[1].Name = "Shailesh Ubhe";
    GroupLeader[1].textColor = WhiteColor;
    GroupLeader[1].positionY = y;
    GroupLeader[1].height = subTitleHeight;

    // Group Members
    y = y - 2.0f - fArrowHeight;

    Members[0].Name = "Group Members";
    Members[0].textColor = RedColor;
    Members[0].positionY = y;
    Members[0].height = titleHeight;

    y = y - titleHeight - charSpecing;

    Members[1].Name = "Ayush Jaiswal";
    Members[1].textColor = WhiteColor;
    Members[1].positionY = y;
    Members[1].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[2].Name = "Bhagyashree Chavan";
    Members[2].textColor = WhiteColor;
    Members[2].positionY = y;
    Members[2].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[3].Name = "Bhushan Rane";
    Members[3].textColor = WhiteColor;
    Members[3].positionY = y;
    Members[3].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[4].Name = "Imran Pathan";
    Members[4].textColor = WhiteColor;
    Members[4].positionY = y;
    Members[4].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[5].Name = "Himanshu Chowdhary";
    Members[5].textColor = WhiteColor;
    Members[5].positionY = y;
    Members[5].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[6].Name = "Nitin Kolapkar";
    Members[6].textColor = WhiteColor;
    Members[6].positionY = y;
    Members[6].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[7].Name = "Vishal Kamble";
    Members[7].textColor = WhiteColor;
    Members[7].positionY = y;
    Members[7].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[8].Name = "Vaibhav Ile";
    Members[8].textColor = WhiteColor;
    Members[8].positionY = y;
    Members[8].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[9].Name = "Radhika Vishwakarma";
    Members[9].textColor = WhiteColor;
    Members[9].positionY = y;
    Members[9].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[10].Name = "Dr. Shripad Bhatlawande";
    Members[10].textColor = WhiteColor;
    Members[10].positionY = y;
    Members[10].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[11].Name = "Vighnesh Nair";
    Members[11].textColor = WhiteColor;
    Members[11].positionY = y;
    Members[11].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    Members[12].Name = "Vinayak Mali";
    Members[12].textColor = WhiteColor;
    Members[12].positionY = y;
    Members[12].height = subTitleHeight;

    // Special Thanks
    y = y - 2.0f - fArrowHeight;

    SpecialThanks[0].Name = "Special Thanks to";
    SpecialThanks[0].textColor = RedColor;
    SpecialThanks[0].positionY = y;
    SpecialThanks[0].height = titleHeight;

    y = y - titleHeight - charSpecing;

    SpecialThanks[1].Name = "Rama Gokhale Madam";
    SpecialThanks[1].textColor = WhiteColor;
    SpecialThanks[1].positionY = y;
    SpecialThanks[1].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    SpecialThanks[2].Name = "Pradnya Gokhale Madam";
    SpecialThanks[2].textColor = WhiteColor;
    SpecialThanks[2].positionY = y;
    SpecialThanks[2].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    SpecialThanks[3].Name = "Yogeshwar Shukla Sir";
    SpecialThanks[3].textColor = WhiteColor;
    SpecialThanks[3].positionY = y;
    SpecialThanks[3].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    SpecialThanks[4].Name = "Radhika Shukla Madam";
    SpecialThanks[4].textColor = WhiteColor;
    SpecialThanks[4].positionY = y;
    SpecialThanks[4].height = subTitleHeight;

    y = y - titleHeight - charSpecing;

    SpecialThanks[5].Name = "All RTR Groups";
    SpecialThanks[5].textColor = WhiteColor;
    SpecialThanks[5].positionY = y;
    SpecialThanks[5].height = subTitleHeight;

    // Sir Name
    y = y - 2.0f - fArrowHeight;

    SirName[0].Name = "Ignited By";
    SirName[0].textColor = RedColor;
    SirName[0].positionY = y;
    SirName[0].height = titleHeight;

    y = y - titleHeight - charSpecing;

    SirName[1].Name = "Dr. Vijay D. Gokhale Sir";
    SirName[1].textColor = WhiteColor;
    SirName[1].positionY = y;
    SirName[1].height = subTitleHeight;

    // Thank You
    y = y - 2.0f - fArrowHeight;
    ThankYou[0].Name = "Thank You";
    ThankYou[0].textColor = WhiteColor;
    ThankYou[0].positionY = y;
    ThankYou[0].height = titleHeight;

    ShowEndCredits(ProjectLead, 2);
    ShowEndCredits(GroupLeader, 2);
    ShowEndCredits(Members, 13);
    ShowEndCredits(SpecialThanks, 6);
    ShowEndCredits(SirName, 2);
    ShowEndCredits(ThankYou, 1);

    yAnimatePosition = yAnimatePosition + 0.03f;
}
