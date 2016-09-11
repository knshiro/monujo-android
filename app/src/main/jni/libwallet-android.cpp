#include <jni.h>

#include <wallet/wallet2.h>

JNIEXPORT jstring JNICALL
Java_me_ugo_monujo_MainActivity_getMsgFromJni(JNIEnv *env, jobject instance) {

   // TODO

   return (*env)->NewStringUTF(env, "Hello From Jni");
}

JNIEXPORT void JNICALL
Java_me_ugo_monujo_Wallet_initialise(JNIEnv *env, jobject instance) {

    tools::wallet2 *wallet = new tools::wallet2;
    // TODO

}