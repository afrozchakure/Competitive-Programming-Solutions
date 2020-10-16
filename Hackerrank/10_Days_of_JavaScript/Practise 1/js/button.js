var btn = document.createElement('button');

// Button's id
btn.id = 'btn';


// Button's innerHTML 
btn.innerHTML = 0;
btn.onclick = function() {
    btn.innerHTML++;
}

document.body.appendChild(btn);