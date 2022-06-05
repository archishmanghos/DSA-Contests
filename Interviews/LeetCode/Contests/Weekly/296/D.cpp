string beforeCursor, afterCursor;
int nBefore, nAfter;
TextEditor(){
    beforeCursor = afterCursor = "";
    nBefore = nAfter = 0;
}

void addText(string text) {
    beforeCursor += text;
    nBefore += text.size();
    printStatus();
}

int deleteText(int k) {
    int canDelete = min(k, nBefore);
    for(int i = 1; i <= canDelete; i++) beforeCursor.pop_back();
    nBefore -= canDelete;
    return canDelete;
}

string cursorLeft(int k) {
    int moveCursor = min(k, nBefore);
    string addToAfter = "";
    while(moveCursor--){
        addToAfter += beforeCursor.back();
        beforeCursor.pop_back();
        nBefore -= 1;
        nAfter += 1;
    }

    reverse(addToAfter.begin(), addToAfter.end());
    afterCursor = addToAfter + afterCursor;
    int displayText = min(nBefore, 10);
    return beforeCursor.substr(nBefore - displayText, displayText);
}

string cursorRight(int k) {
    int moveCursor = min(k, nAfter);
    reverse(afterCursor.begin(), afterCursor.end());
    while(moveCursor--){
        beforeCursor += afterCursor.back();
        afterCursor.pop_back();
        nBefore += 1;
        nAfter -= 1;
    }

    reverse(afterCursor.begin(), afterCursor.end());
    int displayText = min(nBefore, 10);
    return beforeCursor.substr(nBefore - displayText, displayText);
}