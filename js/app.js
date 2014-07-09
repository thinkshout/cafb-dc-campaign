$(document).ready(function(){
  $('.donation-amount').click(function(evt){
    evt.preventDefault();
    $('#donation-input').attr('value', $(this).text());
  });

  $('#no-end').click(function(){
    $('#campaign-dates').fadeToggle();  
  });

  $('#team-form, #indy-form').hide();
  $('#team, #indy').click(function(){
    var forms = '#' + $(this).attr('id') + '-form';
    formToShow = $(forms);
    if (forms == '#indy-form'){
      formToShow.fadeIn(); 
      $('#team-form').hide();
    } else {
      formToShow.fadeIn(); 
      $('#indy-form').hide();
    }
     
  });
});

$(document).foundation();
