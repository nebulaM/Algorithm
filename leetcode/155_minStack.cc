typedef struct {
    int mMaxSize;
    int mCurrentPos;
    long mMin;
    long* mStack;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* mMinStack=malloc(sizeof(MinStack));
    mMinStack->mStack=(long *)malloc(maxSize*sizeof(long));
    mMinStack->mCurrentPos=-1;
    mMinStack->mMaxSize=maxSize;
    mMinStack->mMin=LONG_MIN;
    return mMinStack;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->mCurrentPos >= obj->mMaxSize-1){
        return;
    }
    if(obj->mCurrentPos==-1){
        obj->mStack[++(obj->mCurrentPos)]=(long)x;
        obj->mMin=(long)x;
    }
    else{
		//store difference btw x and mMin
		//https://discuss.leetcode.com/topic/4953/share-my-java-solution-with-only-one-stack
        obj->mStack[++(obj->mCurrentPos)]=(long)x-obj->mMin;
        if((long)x<obj->mMin){
            obj->mMin=(long)x;
        }
    }
}

void minStackPop(MinStack* obj) {
    if(obj->mCurrentPos<=-1){
        return;
    }
    if(obj->mStack[obj->mCurrentPos]<0){
        obj->mMin-=obj->mStack[obj->mCurrentPos];
    }
    obj->mCurrentPos--;
	//empty stack, reset min value to LONG_MIN
    if(obj->mCurrentPos==-1){
        obj->mMin=LONG_MIN;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->mCurrentPos<=-1){
        return NULL;
    }
	//only one element
    if(obj->mCurrentPos==0){
        return (int)obj->mStack[obj->mCurrentPos];
    }
	//add mMin if positive, since we store the difference
    if(obj->mStack[obj->mCurrentPos]>0){
        return (int)obj->mStack[obj->mCurrentPos]+obj->mMin;
    }else{
        return (int)obj->mMin;
    }
}

int minStackGetMin(MinStack* obj) {
    return (int)obj->mMin;
}

void minStackFree(MinStack* obj) {
    free(obj->mStack);
    obj->mStack=NULL;
    free(obj);
    obj=NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */