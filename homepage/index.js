document.addEventListener("DOMContentLoaded", function() {
    let mode = document.querySelector('#mode');
    mode.addEventListener('click', function() {
    var element = document.body;
    element.classList.toggle("light-mode");
    if (mode.innerHTML == "Switch to Light Mode")
    {
        mode.innerHTML = "Switch to Dark Mode";
    }
    else if (mode.innerHTML == "Switch to Dark Mode")
    {
        mode.innerHTML = "Switch to Light Mode";
    }
    });
});