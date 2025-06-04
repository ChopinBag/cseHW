async function fetchiApi() {
    let url;
    try{ response = fetch(url);
    if (!response.ok) {
        throw new Error('네트워크 오류');
    }
    const data = await response.json();
    console.log(data);
}   catch(error) {
    console.log('error');
}
}
function displayData() {
    const dataDiv = document.getElementById('dataDiv');
    dataDiv.innerHTML = `<h2>${data.title}</h2>
    <p>${data.body}`;
}

window.onload = fetchiApi;