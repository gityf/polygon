# polygon
to check whether a point is in polygon or not.

Unit test case:

    // | ---3--5---> x axis
    // |   /\
    // |  /  \
    // | /    \
    // 5 -------
    // v
    // y axis

    // --------
    // |      |
    // |      |
    // --------
    //
    // 1-------100000--->x axis 
    // | --------
    // | |      |
    // 2 --------
    // v
    // y axis

    // ---1----------10--------> x axis
    // |  ----    ----
    // |  |  |    |  |
    // |  |  ------  |
    // |  |          |
    // |  |          |
    // 10 ------------
    // |
    // v
    // y axis

    // ---1----------10--------> x axis
    // |     ------
    // |     |    |
    // |  |---    ---|
    // |  |          |
    // |  |          |
    // 10 ------------
    // |
    // v
    // y axis
    // ---1--------8---10---15----> x axis
    // |  -----    ------
    // |  \   |    |      \
    // |   \  ------       \
    // |   /                |
    // |  /                 |
    // 10 -------------------
    // |
    // v
    // y axis
