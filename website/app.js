/*
 * Author: Dylan INNOU
 * Access token: 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
 */


/// Animated logo 

const text = document.querySelector('.fancy');
const strText = text.textContent;
const splitText = strText.split("");
text.textContent = "";

for(let i=0; i < splitText.length; i++ ){
    text.innerHTML += "<span>" + splitText[i] + "</span>"
}

let char = 0;
let timer = setInterval(onTick, 50);

function onTick(){
    const span = text.querySelectorAll('span')[char];
    span.classList.add('fade');
    char++
    if (char === splitText.length){
        complete();
        return;
    }
}

function complete(){
    clearInterval(timer);
    timer = null;
}

/// Responsive menu

const toggleButton = document.getElementsByClassName('toggle-button')[0]
const navbarLinks = document.getElementsByClassName('navbar-links')[0]

toggleButton.addEventListener('click', () => {
    navbarLinks.classList.toggle('active')
})

/// Github API

const divResult = document.getElementById('scroll')

async function pullRequest() {
    const headers = {
        'Authorization' : `Token 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`
    }

    const url = 'https://api.github.com/search/issues?q=+type:pr+org:Epilearns'

    const response = await fetch(url, {
        "method": "GET",
        "headers": headers
    })

    const result = await response.json()

    result.items.forEach(i => {
        /*const pr = document.createElement('div')
        //pr.textContent = i.title + '\n' + i.body

        const title = document.createElement('p')
        title.textContent = i.title

        const content = document.createElement('p')
        content.textContent = i.body

        pr.appendChild(title)
        pr.appendChild(content)*/
        const pr = document.createElement("a")
        pr.textContent = i.title
        divResult.appendChild(pr)
        divResult.appendChild(document.createElement('br'))
    });
}

pullRequest()
