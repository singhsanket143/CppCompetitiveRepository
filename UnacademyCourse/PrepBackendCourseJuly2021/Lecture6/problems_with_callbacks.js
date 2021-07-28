var purchaseInfo = { /*some key values*/  };


function trackCheckout(options, callback) {
    processOptions(options);
    for(var i = 0; i < 5; i++) {
        callback();
    }
}

trackCheckout(purchaseInfo, function finish() {
    chargeCreditCard(purchaseInfo);
    showThankYouPage();
});




// trackCheckout -> given to us by an external api