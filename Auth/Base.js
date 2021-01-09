import firebase from "firebase/app";
import "firebase/auth";

const firebaseConfig = {
  apiKey: "AIzaSyB8gWB2EDbzF9NSWx2INiV3QHRIbX1Fqz8",
  authDomain: "srcwabt-ccdcf.firebaseapp.com",
  projectId: "srcwabt-ccdcf",
  storageBucket: "srcwabt-ccdcf.appspot.com",
  messagingSenderId: "586505784414",
  appId: "1:586505784414:web:2ee099bfefd1a99f25f8cf"
};

firebase.initializeApp(firebaseConfig);

export const firebaseInstance = firebase;
export const authService = firebase.auth();