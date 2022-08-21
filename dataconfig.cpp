#include "dataconfig.h"

dataconfig::dataconfig(QObject *parent)
    : QObject{parent}
{
    //第一关
    int array1[4][4] = {{1, 1, 1, 1},
                        {1, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 1, 0, 1}};
    QVector<QVector <int>> v1;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv1;
        for(int j = 0; j < 4; j++)
        {
            vv1.push_back(array1[i][j]);
        }
        v1.push_back(vv1);
    }
    mData.insert(1, v1);

    //第二关
    int array2[4][4] = {{0, 0, 1, 1},
                        {0, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 1, 0, 1}};
    QVector<QVector <int>> v2;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv2;
        for(int j = 0; j < 4; j++)
        {
            vv2.push_back(array2[i][j]);
        }
        v2.push_back(vv2);
    }
    mData.insert(2, v2);

    //第三关
    int array3[4][4] = {{1, 0, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}};
    QVector<QVector <int>> v3;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv3;
        for(int j = 0; j < 4; j++)
        {
            vv3.push_back(array3[i][j]);
        }
        v3.push_back(vv3);
    }
    mData.insert(3, v3);

    //第四关
    int array4[4][4] = {{1, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}};
    QVector<QVector <int>> v4;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv4;
        for(int j = 0; j < 4; j++)
        {
            vv4.push_back(array4[i][j]);
        }
        v4.push_back(vv4);
    }
    mData.insert(4, v4);

    //第五关
    int array5[4][4] = {{0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}};
    QVector<QVector <int>> v5;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv5;
        for(int j = 0; j < 4; j++)
        {
            vv5.push_back(array5[i][j]);
        }
        v5.push_back(vv5);
    }
    mData.insert(5, v5);

    //第六关
    int array6[4][4] = {{0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}};
    QVector<QVector <int>> v6;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv6;
        for(int j = 0; j < 4; j++)
        {
            vv6.push_back(array6[i][j]);
        }
        v6.push_back(vv6);
    }
    mData.insert(6, v6);

    //第七关
    int array7[4][4] = {{1, 0, 0, 0},
                        {1, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 1, 1}};
    QVector<QVector <int>> v7;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv7;
        for(int j = 0; j < 4; j++)
        {
            vv7.push_back(array7[i][j]);
        }
        v7.push_back(vv7);
    }
    mData.insert(7, v7);

    //第八关
    int array8[4][4] = {{1, 0, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}};
    QVector<QVector <int>> v8;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv8;
        for(int j = 0; j < 4; j++)
        {
            vv8.push_back(array8[i][j]);
        }
        v8.push_back(vv8);
    }
    mData.insert(8, v8);

    //第九关
    int array9[4][4] = {{1, 0, 0, 1},
                        {0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}};
    QVector<QVector <int>> v9;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv9;
        for(int j = 0; j < 4; j++)
        {
            vv9.push_back(array9[i][j]);
        }
        v9.push_back(vv9);
    }
    mData.insert(9, v9);

    //第十关
    int array10[4][4] = {{1, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}};
    QVector<QVector <int>> v10;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv10;
        for(int j = 0; j < 4; j++)
        {
            vv10.push_back(array10[i][j]);
        }
        v10.push_back(vv10);
    }
    mData.insert(10, v10);

    //第十一关
    int array11[4][4] = {{1, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 1, 0, 0},
                        {1, 0, 0, 1}};
    QVector<QVector <int>> v11;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv11;
        for(int j = 0; j < 4; j++)
        {
            vv11.push_back(array11[i][j]);
        }
        v11.push_back(vv11);
    }
    mData.insert(11, v11);

    //第十二关
    int array12[4][4] = {{1, 1, 1, 1},
                        {1, 0, 1, 0},
                        {0, 1, 0, 0},
                        {0, 0, 0, 1}};
    QVector<QVector <int>> v12;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv12;
        for(int j = 0; j < 4; j++)
        {
            vv12.push_back(array12[i][j]);
        }
        v12.push_back(vv12);
    }
    mData.insert(12, v12);

    //第十三关
    int array13[4][4] = {{1, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 1}};
    QVector<QVector <int>> v13;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv13;
        for(int j = 0; j < 4; j++)
        {
            vv13.push_back(array13[i][j]);
        }
        v13.push_back(vv13);
    }
    mData.insert(13, v13);

    //第十四关
    int array14[4][4] = {{1, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 0},
                        {1, 0, 0, 1}};
    QVector<QVector <int>> v14;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv14;
        for(int j = 0; j < 4; j++)
        {
            vv14.push_back(array14[i][j]);
        }
        v14.push_back(vv14);
    }
    mData.insert(14, v14);

    //第十五关
    int array15[4][4] = {{1, 1, 1, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 0},
                        {1, 1, 0, 1}};
    QVector<QVector <int>> v15;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv15;
        for(int j = 0; j < 4; j++)
        {
            vv15.push_back(array15[i][j]);
        }
        v15.push_back(vv15);
    }
    mData.insert(15, v15);

    //第十六关
    int array16[4][4] = {{1, 1, 1, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 0},
                        {1, 1, 1, 1}};
    QVector<QVector <int>> v16;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv16;
        for(int j = 0; j < 4; j++)
        {
            vv16.push_back(array16[i][j]);
        }
        v16.push_back(vv16);
    }
    mData.insert(16, v16);

    //第十七关
    int array17[4][4] = {{1, 1, 1, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 1},
                        {1, 1, 1, 1}};
    QVector<QVector <int>> v17;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv17;
        for(int j = 0; j < 4; j++)
        {
            vv17.push_back(array17[i][j]);
        }
        v17.push_back(vv17);
    }
    mData.insert(17, v17);

    //第十八关
    int array18[4][4] = {{1, 1, 1, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 1},
                        {1, 1, 1, 1}};
    QVector<QVector <int>> v18;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv18;
        for(int j = 0; j < 4; j++)
        {
            vv18.push_back(array18[i][j]);
        }
        v18.push_back(vv18);
    }
    mData.insert(18, v18);

    //第十九关
    int array19[4][4] = {{1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 0, 0, 1},
                        {1, 1, 1, 1}};
    QVector<QVector <int>> v19;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv19;
        for(int j = 0; j < 4; j++)
        {
            vv19.push_back(array19[i][j]);
        }
        v19.push_back(vv19);
    }
    mData.insert(19, v19);

    //第二十关
    int array20[4][4] = {{0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};
    QVector<QVector <int>> v20;
    for(int i = 0; i < 4; i++)
    {
        QVector<int>vv20;
        for(int j = 0; j < 4; j++)
        {
            vv20.push_back(array20[i][j]);
        }
        v20.push_back(vv20);
    }
    mData.insert(20, v20);
}
