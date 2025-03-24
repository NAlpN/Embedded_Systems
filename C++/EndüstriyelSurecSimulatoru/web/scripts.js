let calisiyor = false;

function baslatSimulasyon() {
    if (!calisiyor) {
        calisiyor = true;
        document.getElementById("makineDurumu").innerText = "Makine Çalışıyor...";
    }
}

function durdurSimulasyon() {
    if (calisiyor) {
        calisiyor = false;
        document.getElementById("makineDurumu").innerText = "Makine Durduruldu.";
    }
}