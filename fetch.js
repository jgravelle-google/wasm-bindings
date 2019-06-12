// JS version of fetch program

async function fetchAsyncAwait() {
  var response = await fetch('data/foo.json');
  var data = await response.json();
  console.log(data.someProp);
}

function fetchPromise() {
  fetch('data/foo.json')
    .then(function(response) {
      return response.json();
    })
    .then(function(data) {
      console.log(data.someProp);
    });
}
